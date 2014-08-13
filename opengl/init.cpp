#include "resource.h"
#include "primetives.h"

int x;
int y;

HWND  g_hWnd = NULL;
HDC   g_hDC  = NULL;
HGLRC g_hRC  = NULL;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void init(void);
void shutDown(void);
void render(void);

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR     lpCmdLine,
                   int       nCmdShow)
{
    WNDCLASSEX winClass; 
	MSG        uMsg;

    memset(&uMsg,0,sizeof(uMsg));
    
	winClass.lpszClassName = "MY_WINDOWS_CLASS";
	winClass.cbSize        = sizeof(WNDCLASSEX);
	winClass.style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	winClass.lpfnWndProc   = WindowProc;
	winClass.hInstance     = hInstance;
    winClass.hIcon	       = LoadIcon(hInstance, (LPCTSTR)IDI_OPENGL_ICON);
    winClass.hIconSm	   = LoadIcon(hInstance, (LPCTSTR)IDI_OPENGL_ICON);
	winClass.hCursor       = LoadCursor(NULL, IDC_ARROW);
	winClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	winClass.lpszMenuName  = NULL;
	winClass.cbClsExtra    = 0;
	winClass.cbWndExtra    = 0;

	if( !RegisterClassEx(&winClass) )
		return E_FAIL;

	g_hWnd = CreateWindowEx(NULL, "MY_WINDOWS_CLASS", 
                            "OpenGL - Initialization",
						    WS_OVERLAPPEDWINDOW | WS_VISIBLE,
					        0, 0, 640, 480, NULL, NULL, hInstance, NULL);

	if(g_hWnd == NULL)
		return E_FAIL;

    ShowWindow(g_hWnd, nCmdShow);
    UpdateWindow(g_hWnd);

	init();

	while(uMsg.message != WM_QUIT)
	{
		if(PeekMessage( &uMsg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&uMsg);
			DispatchMessage(&uMsg);
		}
        else
			render();
	}

	shutDown();

    UnregisterClass("MY_WINDOWS_CLASS", winClass.hInstance);

	return uMsg.wParam;
}

LRESULT CALLBACK WindowProc(HWND   hWnd, 
							UINT   msg, 
							WPARAM wParam, 
							LPARAM lParam)
{
    switch(msg)
	{
		// Обработка нажатий клавиш
        case WM_KEYDOWN:
		{
			switch(wParam)
			{
				// Если нажали Esc - выходим
				case VK_ESCAPE:
					PostQuitMessage(0);
					break;
				case VK_LEFT:
					glTranslatef(-0.01,0.f,0.f);
					break;
				
				case VK_RIGHT:
					glTranslatef(0.01,0.f,0.f);
					break;
					
				case VK_UP:
					glTranslatef(0.f,0.01,0.f);
					break;
					
				case VK_DOWN:
					glTranslatef(0.f,-0.01,0.f);
					break;
			}

		}
        break;

		case WM_LBUTTONDOWN:
		{
			switch(wParam)
			{
				case MK_LBUTTON:
				{
					x=LOWORD(lParam);
					y=HIWORD(lParam);
				}
					break;
			}
			
		}
		break;

		case WM_MOUSEMOVE:
		{
			switch(wParam)
			{
				case MK_LBUTTON:
				{
					int dx=LOWORD(lParam);
					int dy=HIWORD(lParam);
			
					glRotatef((dx-x)/100.f ,0.f,1.f,0.f);
					
					glRotatef((dy-y)/100.f ,1.f,0.f,0.f);
				}
				break;
			}
		}
		break;

		// Изменение размера окна
		case WM_SIZE:
		{
			int nWidth  = LOWORD(lParam);		// Ширина
			int nHeight = HIWORD(lParam);		// Высота
			glViewport(0, 0, nWidth, nHeight);	// Вьюпорт OpenGL

			glMatrixMode(GL_PROJECTION);		// Матрица проекции
			glLoadIdentity();					// Сбрасываем

			// Устанавливаем перспективу OpenGL (угол взгляда, аспект ширины и высоты, ближайшее и дальнее отсечение взгляда)
			//gluPerspective( 45.0, (GLdouble)nWidth / (GLdouble)nHeight, 0.1, 100.0);
		}
		break;

		// Если закрыли окно - выходим 
		case WM_CLOSE:
		{
			PostQuitMessage(0);	
		}

		// Если уничтожили окно - выходим
        case WM_DESTROY:
		{
            PostQuitMessage(0);
		}
        break;
		
		// Умолчание
		default:
		{
			return DefWindowProc( hWnd, msg, wParam, lParam );
		}
		break;
	}

	return 0;
}

void init( void )
{
	PIXELFORMATDESCRIPTOR pfd;
	memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));

    pfd.nSize      = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion   = 1;
    pfd.dwFlags    = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 16;
	pfd.cDepthBits = 16;

	g_hDC = GetDC( g_hWnd );
	GLuint iPixelFormat = ChoosePixelFormat( g_hDC, &pfd );

	if( iPixelFormat != 0 )
	{
		PIXELFORMATDESCRIPTOR bestMatch_pfd;
		DescribePixelFormat( g_hDC, iPixelFormat, sizeof(pfd), &bestMatch_pfd );

		if( bestMatch_pfd.cDepthBits < pfd.cDepthBits )
		{
			return;
		}

		if( SetPixelFormat( g_hDC, iPixelFormat, &pfd) == FALSE )
		{
			DWORD dwErrorCode = GetLastError();
			return;
		}
	}
	else
	{
		DWORD dwErrorCode = GetLastError();
		return;
	}

	g_hRC = wglCreateContext( g_hDC );
	wglMakeCurrent( g_hDC, g_hRC );

	//glClearColor( 0.0f, 0.0f, 0.0f, 1.0f ); // Цвет вьюпорта OpenGL
}

void shutDown( void )	
{
	if( g_hRC != NULL )
	{
		wglMakeCurrent( NULL, NULL );
		wglDeleteContext( g_hRC );
		g_hRC = NULL;
	}

	if( g_hDC != NULL )
	{
		ReleaseDC( g_hWnd, g_hDC );
		g_hDC = NULL;
	}
}

void render()	
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glPushMatrix();
	glRotatef(-5.f ,1.f,1.f,0.f);
	glBegin(GL_TRIANGLES);
		//glColor3f(0.5,0.f,0.f);


		Color4 color(0.5,0.5f,0.f,0.5);
		Box box(0.5, 0.5, 0.5, color);
		box.draw();
	glEnd();
	glPopMatrix();

	glDisable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);

	SwapBuffers( g_hDC );
}