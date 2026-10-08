#include <sys/types.h>
#include <psxetc.h>
#include <psxgte.h>
#include <psxgpu.h>
#include <psxapi.h>
#include <psxpad.h>

// Buffer untuk *controller* (joystick)
char pad_buff[2][34];

void init_system() {
    // Inisialisasi sistem PS1
    ResetCallback();
    SetVideoMode(MODE_PAL); 
    
    // Setup font dasar PS1
    FntLoad(960, 0);
    FntOpen(10, 10, 300, 200, 0, 100);
    
    // Inisialisasi controller
    InitPAD(&pad_buff[0][0], 34, &pad_buff[1][0], 34);
    StartPAD();
}

int main() {
    init_system();
    
    while(1) {
        // Bersihkan teks sebelumnya
        FntFlush(-1);
        
        // Tulis teks intro di layar
        FntPrint("PROJECT AYDIN: JAKARTA UTARA\n\n");
        FntPrint("Bandara Soekarno-Hatta...\n");
        FntPrint("Udah lama gw gak balik ke Gang Mesjid.\n\n");
        FntPrint("Naban, Baim, Iban... pada kemana ya?\n\n");
        FntPrint("Tekan tombol START untuk mulai...");
        
        // Update layar (tampilkan teks)
        DrawSync(0);
        VSync(0);
    }
    return 0;
}
