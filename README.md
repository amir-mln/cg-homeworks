# Homeworks of Computer Graphics Course of University

FOllow these steps for project setup in `dev c++`:

- Download the following folder and extract it's contents. `https://drive.google.com/file/d/0B5k4Y85A4nwRdjNFWlEweEJmNjQ/view?usp=sharings`

- Copy and paste the files graphics and winbgim into `C:\Program Files (x86)\Dev-Cpp\MinGW64\include` and `C:\Program Files (x86)\Dev-Cpp\MinGW64\x86_64-w64-mingw32\include`. The path may vary slightly depending on where you install Dev C++, it's usually installed in the above specified paths by default.

- Copy and paste the file libbgi.a into `C:\Program Files (x86)\Dev-Cpp\MinGW64\lib` and `C:\Program Files (x86)\Dev-Cpp\MinGW64\x86_64-w64-mingw32\lib`

- Open a new project in Dev C++ and choose Empty project.

- Press `Ctrl+H` and choose the parameters tab in the window that opens. Copy paste the following in the linter column: `-lbgi -lgdi32 -luser32`

- In the title bar, choose `TDM-GCC 4.9.2 32-bit` Profiling option in the dropdown
