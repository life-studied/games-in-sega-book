/**
 * @file Input.hpp
 * @author yunyin (yunyin_jayyi@qq.com)
 * @brief no-buffering input for multiple platforms
 * @version 0.1
 * @date 2024-03-18
 * 
 * @copyright Copyright (c) 2024
 * 
*/
#pragma once

#ifdef _WIN32
    #include <conio.h>
#endif

#ifdef __linux__
    #include <termio.h>
    inline int getch(void)
    {
        struct termios tm, tm_old;
        int fd = 0, ch;
    
        if (tcgetattr(fd, &tm) < 0) {//保存现在的终端设置
            return -1;
        }
    
        tm_old = tm;
        cfmakeraw(&tm);//更改终端设置为原始模式，该模式下所有的输入数据以字节为单位被处理
        if (tcsetattr(fd, TCSANOW, &tm) < 0) {//设置上更改之后的设置
            return -1;
        }

        ch = getchar();
        if (tcsetattr(fd, TCSANOW, &tm_old) < 0) {//更改设置为最初的样子
            return -1;
        }

        return ch;
    }

#endif