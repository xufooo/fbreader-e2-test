#ifndef QWALLPAPER_H
#define QWALLPAPER_H

class QWallpaper {

public:

    enum Mode
    {
        UseSysWallpaper,
        UseAppWallpaper,
        Off
    };
    
    static void setAppWallpaperMode(Mode mode);
    
};

#endif // QWALLPAPER_H

