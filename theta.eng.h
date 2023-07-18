#include <string>
#include <fstream>

namespace theta {
    struct vtovcon {
        int* vtexCon;
        int size;
    };

    struct rot3D {
        double X;
        double Y;
        double Z;
        bool radian;
    };

    struct Pos3D{
        double X;
        double Y;
        double Z;
    };
    
    struct vTex {
        Pos3D pos;
        vtovcon vtexCon;
        rot3D rot;
    };

    struct ln {
        vTex a;
        vTex b;
        rot3D rotation;
        double length;
    };

    class BUFFER {
    private:
        std::ifstream custBuffer;
    public:
        void GET_RULES();
        bool assignBuffer(const std::string& filename);
        void clearBuffer();
        std::string getRawLine(int line);
        vTex getVtex(int line);
        // Other commands and member functions
    };
    
    class CONSOLE {
    public:
        void openConsole();
    };
    
    class VTEX {
    private:
        vTex vtex;
    public:
        class init {
        public:
            vTex vTovCon();
            vTex pos();
        };
        
        class transform {
        public:
            class move {
            public:
                vTex linear(double dist, rot3D rotation);
                vTex quadratic(double X, double Y, rot3D rotation);
                vTex cubic(double X, double Y, double Z, rot3D rotation);
            };
            class rotate{
                public:
                vTex std(rot3D rotation, bool euler);
                vTex std(rot3D rotation,);
            };
        };
    };

    class LINE {
        private:
        ln line;
        public:
        class init{
            
        };
    };
}
