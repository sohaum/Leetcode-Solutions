class Robot {
public:
    int w,h,perimeter;
    int x,y,dir; // 0:E, 1:N, 2:W, 3:S
    Robot(int width, int height) {
        w=width;
        h=height;
        perimeter=2*(w+h-2);
        x=0;
        y=0;
        dir=0; // East
    }
    void step(int num) {
        num%=perimeter;
        // special case: full loop
        if (num==0 && x==0 && y==0) {
            dir=3; // South
            return;
        }

        while (num>0) {
            if (dir==0) { // East
                int move=min(num,w-1-x);
                x+=move;
                num-=move;
                if (num>0) dir=1;
            }
            else if (dir==1) { // North
                int move=min(num,h-1- y);
                y+=move;
                num-=move;
                if (num>0) dir=2;
            }
            else if (dir==2) { // West
                int move=min(num,x);
                x-=move;
                num-=move;
                if (num>0) dir=3;
            }
            else { // South
                int move=min(num,y);
                y-=move;
                num-=move;
                if (num>0) dir=0;
            }
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        if (dir==0) return "East";
        if (dir==1) return "North";
        if (dir==2) return "West";
        return "South";
    }
};