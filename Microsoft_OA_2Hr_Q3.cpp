// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int getBrushStrokes(vector<int> &buildings) 
{
    long long brushCount = 0, prevHt = 0;
    for(int i=0; i<(int)buildings.size(); ++i)
    {
        if(buildings[i] > prevHt)
            brushCount += (buildings[i] - prevHt);
        prevHt = buildings[i];
        if(ans > 1000000000)
            return -1;
    }
    return brushCount;
}