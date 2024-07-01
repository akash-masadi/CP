#include <bits/stdc++.h>
using namespace std;

// Function to calculate Euclidean distance
double find(double x, double y,
            vector<vector<int> >& p)
{

    double mind = 0;
    for (int i = 0; i < p.size(); i++) {

        double a = p[i][0], b = p[i][1];
        mind += sqrt((x - a) * (x - a)
                     + (y - b) * (y - b));
    }

    return mind;
}

// Function to calculate the minimum sum
// of the euclidean distances to all points
double getMinDistSum(vector<vector<int> >& p)
{

    // Calculate the centroid
    double x = 0, y = 0;
    for (int i = 0; i < p.size(); i++) {
        x += p[i][0];
        y += p[i][1];
    }
    x = x / p.size();
    y = y / p.size();

    // Calculate distance of all
    // points
    double mind = find(x, y, p);

    return mind;
}

// Driver Code
int main()
{

    // Initializing the points
    vector<vector<int> > vec
        = { { 0, 1 }, { 1, 0 }, { 1, 2 }, { 2, 1 } };

    double d = getMinDistSum(vec);
    cout << d << endl;

    return 0;
}
