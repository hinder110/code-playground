#include <stdio.h>
#include <windows.h>

// 定义常用键的名称
const char* GetKeyName(int vkCode) {
    switch (vkCode) {
        case VK_SPACE: return "Space";
        case VK_RETURN: return "Enter";
        case VK_SHIFT: return "Shift";
        case VK_CONTROL: return "Ctrl";
        case VK_MENU: return "Alt";
        case VK_BACK: return "Backspace";
        case VK_TAB: return "Tab";
        case VK_ESCAPE: return "Escape";
        case VK_CAPITAL: return "Caps Lock";
        case VK_LEFT: return "Left Arrow";
        case VK_RIGHT: return "Right Arrow";
        case VK_UP: return "Up Arrow";
        case VK_DOWN: return "Down Arrow";
        default:
            if (vkCode >= 'A' && vkCode <= 'Z') {
                static char keyName[2] = {0};
                keyName[0] = (char)vkCode;
                return keyName;
            }
            if (vkCode >= '0' && vkCode <= '9') {
                static char keyName[2] = {0};
                keyName[0] = (char)vkCode;
                return keyName;
            }
            return "Unknown Key";
    }
}

int main() {
    printf("按键检测程序已启动。按下 Esc 键退出。\n");

    while (1) {
        // 遍历所有可能的键值（0 到 255）
        for (int i = 0; i < 256; i++) {
            // 检测按键是否被按下
            if (GetAsyncKeyState(i) & 0x8000) {
                // 获取按键名称
                const char* keyName = GetKeyName(i);
                printf("按下的键: %s\n", keyName);

                // 如果按下 Esc 键，退出程序
                if (i == VK_ESCAPE) {
                    printf("检测到 Esc 键，程序退出。\n");
                    return 0;
                }

                // 避免重复检测同一个键
                Sleep(100); // 延迟 100 毫秒
            }
        }
    }

    return 0;
}