#include <windows.h>
#include <stdio.h>

HWND find_volume(void) {
	HWND window = NULL;
	HWND found = NULL;
	// Search for window with class "NativeHWNDHost"
	while (window = FindWindowEx(NULL, window, "NativeHWNDHost", NULL))
		// If it has a child with class "DirectUIHWND", it's probably the volume control, I hope?
		if (FindWindowEx(window, NULL, "DirectUIHWND", NULL)) {
			if (found) // uh oh, found more than 1
				return NULL;
			found = window;
		}
	return found;
}

int main(void){
	HWND window = find_volume();
	if (!window) {
		MessageBox(NULL, "Couldn't find volume window", NULL, MB_ICONERROR);
		return 1;
	}
	ShowWindow(window, IsIconic(window) ? SW_RESTORE : SW_MINIMIZE);
	return 0;
}