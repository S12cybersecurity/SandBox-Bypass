#include <windows.h>

using namespace std;

class SysReq {
    private:
        int ram;
        int cores;
    
    public:

        SysReq(){
            this->ram = 0;
            this->cores = 0;
        }

        int getRam(){
            return ram;
        }
        
        int getCores(){
            return cores;
        }

        int ramdetect(){
            MEMORYSTATUSEX memInfo;
            memInfo.dwLength = sizeof(MEMORYSTATUSEX);
            GlobalMemoryStatusEx(&memInfo);
            ram = memInfo.ullTotalPhys / 1024 / 1024;
            return memInfo.ullTotalPhys / 1024 / 1024;
        }

        int coresdetect(){
            SYSTEM_INFO sysInfo;
            GetSystemInfo(&sysInfo);
            cores = sysInfo.dwNumberOfProcessors;
            return sysInfo.dwNumberOfProcessors;
        }

        void getSysInfo(){
            this->ram = ramdetect();
            this->cores = coresdetect();
        }

};
