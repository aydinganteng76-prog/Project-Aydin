#include <sys/types.h>
#include <psxetc.h>
#include <psxgte.h>
#include <psxgpu.h>
#include <psxapi.h>
#include <psxpad.h>

// Buffer untuk controller PS1
char pad_buff[2][34];
int font_id;

void init_system() {
    ResetCallback();
    SetVideoMode(MODE_PAL); 
    
    // Inisialisasi layar dan font
    FntLoad(960, 0);
    font_id = FntOpen(10, 10, 300, 200, 0, 100);
    
    // Inisialisasi tombol controller
    InitPAD(&pad_buff[0][0], 34, &pad_buff[1][0], 34);
    StartPAD();
}

int main() {
    init_system();
    
    while(1) {
        // Bersihkan teks frame sebelumnya
        FntFlush(-1);
        
        // Tulis cerita pembuka Aydin balik ke Jakarta Utara
        FntPrint(font_id, "PROJECT AYDIN: JAKARTA UTARA\n\n");
        FntPrint(font_id, "Bandara Soekarno-Hatta...\n");
        FntPrint(font_id, "Udah lama gw gak balik ke Gang Mesjid.\n\n");
        FntPrint(font_id, "Naban, Baim, Iban... pada kemana ya?\n\n");
        FntPrint(font_id, "Tekan tombol START untuk mulai...");
        
        // Sinkronisasi grafik PS1
        DrawSync(0);
        VSync(0);
    }
    return 0;
}
