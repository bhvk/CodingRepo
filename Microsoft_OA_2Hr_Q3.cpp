//https://stackoverflow.com/questions/56373582/how-can-i-count-how-many-horizontal-brush-strokes-are-required-to-draw-an-array
//Q : How can I count how many horizontal brush strokes are required to draw an array of buildings?

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