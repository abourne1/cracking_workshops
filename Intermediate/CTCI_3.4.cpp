// Tower of Hanoi

class Tower 
{
    Stack *stack;
    int disks;
    
    public:
    Tower() {}
    
    int getIndex() 
    {
        return index;
    }

    void setIndex(int i) 
    {
        index = i;
    }

    int stackSize()
    {
        return this->stack.size();
    }
    
    void add(int value)
    {
        if(!stack.empty() && value >= stack.peek()) {
            cout<<"Error";
            return;
        }
        stack.push(value);
    }
    
    int MoveTopTo(Tower t)
    {
        int disk = stack.pop();
        t.add(disk);
    }
    
    void MoveDisks(int n, Tower d, Tower buffer) 
    {
        if( n > 0 ) {
            // put n-1 elements to the buffer Tower
            MoveDisks(n - 1 , buffer, d);
            // move one last element to the destination
            MoveTopTo(d);
            // put those n-1 back to the destination Tower!
            buffer.moveDisks(n-1, d,this);
            // Done
        }
    }
};

// int main() 
// {
//     int n = 3;
//     Tower towers[3];
    
//     for(int i = 0; i<3; i++) {
//         towers[i].setIndex(i+1);
//         std::cout<<towers[i].stackSize()<<std::endl;
//     }
    
//     for(int i = n-1; i >= 0; i--) {
//         towers[0].add(i);
//     }
    
//     towers[0].moveDisks(n, towers[2], towers[1]);
    
//     return;
// }





// Time complexity: T(n) = 2T(n-1)+1
// exponential time! 
// See more in Rosen Discreet Math textbook