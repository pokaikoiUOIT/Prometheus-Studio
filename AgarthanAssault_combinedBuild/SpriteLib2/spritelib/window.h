#pragma once
#include <string>
#include <memory>
#include <chrono>
#include <functional>

namespace sf {
	class RenderWindow;
	class Color;
}

namespace spritelib
{
	class Sprite;
	class Text;
	class Shapes;
	namespace math {
		class Matrix4x4;
	}

	class Window
	{
		friend Sprite;
		friend Shapes;
		friend Text;
	private:
		Window();
		Window(const Window& obj);

	public:
		enum EventType
		{
			KeyPressed = 5,				// A key was pressed 
			KeyReleased = 6,			// A key was released
			MouseButtonPressed = 9,		// A mouse button was pressed 
			MouseButtonReleased = 10,	// A mouse button was released
			MouseMoved = 11,			// The mouse cursor moved 

			Count	// Keep last -- the total number of event types
		};
		enum Key
		{
			UnknownKey = -1,
			A = 0,        // The A key
			B,            // The B key
			C,            // The C key
			D,            // The D key
			E,            // The E key
			F,            // The F key
			G,            // The G key
			H,            // The H key
			I,            // The I key
			J,            // The J key
			K,            // The K key
			L,            // The L key
			M,            // The M key
			N,            // The N key
			O,            // The O key
			P,            // The P key
			Q,            // The Q key
			R,            // The R key
			S,            // The S key
			T,            // The T key
			U,            // The U key
			V,            // The V key
			W,            // The W key
			X,            // The X key
			Y,            // The Y key
			Z,            // The Z key
			Num0,         // The 0 key
			Num1,         // The 1 key
			Num2,         // The 2 key
			Num3,         // The 3 key
			Num4,         // The 4 key
			Num5,         // The 5 key
			Num6,         // The 6 key
			Num7,         // The 7 key
			Num8,         // The 8 key
			Num9,         // The 9 key
			Escape,       // The Escape key
			LControl,     // The left Control key
			LShift,       // The left Shift key
			LAlt,         // The left Alt key
			LSystem,      // The left OS specific key: window (Windows and Linux), apple (MacOS X), ...
			RControl,     // The right Control key
			RShift,       // The right Shift key
			RAlt,         // The right Alt key
			RSystem,      // The right OS specific key: window (Windows and Linux), apple (MacOS X), ...
			Menu,         // The Menu key
			LBracket,     // The [ key
			RBracket,     // The ] key
			SemiColon,    // The ; key
			Comma,        // The , key
			Period,       // The . key
			Quote,        // The ' key
			Slash,        // The / key
			BackSlash,    // The \ key
			Tilde,        // The ~ key
			Equal,        // The = key
			Dash,         // The - key
			Space,        // The Space key
			Return,       // The Return key
			BackSpace,    // The Backspace key
			Tab,          // The Tabulation key
			PageUp,       // The Page up key
			PageDown,     // The Page down key
			End,          // The End key
			Home,         // The Home key
			Insert,       // The Insert key
			Delete,       // The Delete key
			Add,          // The + key
			Subtract,     // The - key
			Multiply,     // The * key
			Divide,       // The / key
			Left,         // Left arrow
			Right,        // Right arrow
			Up,           // Up arrow
			Down,         // Down arrow
			Numpad0,      // The numpad 0 key
			Numpad1,      // The numpad 1 key
			Numpad2,      // The numpad 2 key
			Numpad3,      // The numpad 3 key
			Numpad4,      // The numpad 4 key
			Numpad5,      // The numpad 5 key
			Numpad6,      // The numpad 6 key
			Numpad7,      // The numpad 7 key
			Numpad8,      // The numpad 8 key
			Numpad9,      // The numpad 9 key
			F1,           // The F1 key
			F2,           // The F2 key
			F3,           // The F3 key
			F4,           // The F4 key
			F5,           // The F5 key
			F6,           // The F6 key
			F7,           // The F7 key
			F8,           // The F8 key
			F9,           // The F9 key
			F10,          // The F10 key
			F11,          // The F11 key
			F12,          // The F12 key
			F13,          // The F13 key
			F14,          // The F14 key
			F15,          // The F15 key
			Pause,        // The Pause key

			KeyCount      // Keep last -- the total number of keyboard keys
		};
		enum Button
		{
			UnknownButton = -1,
			LeftButton = 0,     // The left mouse button
			RightButton,      // The right mouse button
			MiddleButton,     // The middle (wheel) mouse button
			XButton1,   // The first extra mouse button
			XButton2,   // The second extra mouse button
						 
			ButtonCount // Keep last -- the total number of mouse buttons
		};

		/* init
			- gamename is the title that will appear on the titlebar of the window
			- width/height are the dimensions of the window that's being created
			- fullscreen is a boolean, which toggles the game in and out of fullscreen.
		*/
		Window& init(std::string a_gameName, unsigned int a_width = 1280, unsigned int a_height = 720, bool a_fullscreen = false);
		/* update
			- target fps is the frames-per-second that your game will limit itself to. 
			- This function needs to be called every single frame of your game. It is an IMPORTANT part of the main game loop
		*/
		bool update(int a_targetFPS = 60);
		
		/* set_screen_size
			- set the size of the screen that sprites render onto. This can be independant from the window size
		*/
		Window& set_screen_size(unsigned int a_width, unsigned int a_height);
		/* set_size
			- width/height are the dimensions of the window that will be applied
		*/
		Window& set_size(int a_width, int a_height);
		/* set_title
			- gamename is the title that will appear on the titlebar of the window
		*/
		Window& set_title(std::string a_gameName);
		/* set_window_style
			- resizable is a boolean, determining whether you can resize the window
			- titlebar is a boolean, determining whether there will be a title bar on your window
		*/
		Window& set_window_style(bool a_resizable, bool a_titlebar);
		/* set_clear_color
			-red/green/blue are the components of the color that will clear the screen. If absolutely nothing is drawn in your game, 
				it will be this color
		*/
		Window& set_clear_color(unsigned char a_red, unsigned char a_green, unsigned char a_blue);
		/* get_sfml_window
			- returns the sfml window
		*/
		sf::RenderWindow& get_sfml_window();
		/* set_keyboard_callback
			- keyboardFunction is a function to handle keyboard events
				- parameter 1 is a Key
				- parameter 2 is the event			
		*/
		Window& set_keyboard_callback(std::function<void(Key, EventType)> a_keyboardFunction);
		/* set_mouse_callback
			- mouseFunction is a function to handle mouse events
				- parameter 1 is a Mouse Button
				- parameter 2 and 3 are the mouse coordiantes (x and y)
				- parameter 4 is the event
		*/
		Window& set_mouse_callback(std::function<void(Button, int, int, EventType)> a_mouseFunction);

		/* get_delta_time
			- this returns the elapsed time (in seconds) between frames. you can estimate this with:
				approxDelta = 1.0 / TargetFPS
		*/
		float get_delta_time();

		/* get_width 
			- returns the width of the window in pixels
			- getScreenWidth is a boolean. if true, it returns the screen width, otherwise it returns the physical window width
		*/
		int get_width(bool a_getScreenWidth = false);
		/* get_height
			- returns the height of the window in pixels
			- getScreenHeight is a boolean. if true, it returns the screen height, otherwise it returns the physical window height
		*/
		int get_height(bool a_getScreenHeight = false);

		/* get_game_window
			- this returns a handle to the main game window. This is a part of a singleton structure, which means, the window that this function
				returns is the exact same, irregardless of where you call the function from.
		*/
		static Window& get_game_window();
		/* show_mouse
			- showMouse is a boolean. If false, the mouse will be hidden
		*/
		Window& show_mouse(bool a_showMouse);

	private:
		static void cleanup(Window * cleanup);

		static std::shared_ptr<Window> m_mainWindow;

		math::Matrix4x4* m_proj;

		sf::RenderWindow* m_window;
		sf::Color* m_clearColor;
		unsigned int m_screenWidth;
		unsigned int m_screenHeight;
		unsigned int m_width;
		unsigned int m_height;
		std::string m_name;

		float m_deltaTime;

		// Used for the delta time calculation
		std::chrono::steady_clock::time_point m_stop;
		std::chrono::steady_clock::time_point m_start;

		// Used for callback functions
		std::function<void(Button, int, int, EventType)> m_mouseFunction;
		std::function<void(Key, EventType)> m_keyboardFunction;
	};
}