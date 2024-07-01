/*
  Time Complexity: O( N^2 )
  Space Complexity: O( 1 )
  
  where 'N' is the number of the customers.
      
*/

#include <bits/stdc++.h>
#include <math.h>
using namespace std;

//Function to find sum of euclidian distance of a point from all points.
double findDis(vector<vector<double> > &location, pair<double, double> point)
{
    double sum = 0;

    for (int i = 0; i < location.size(); i++)
    {

        double distx = (location[i][0] - point.first);
        double disty = (location[i][1] - point.second);
        sum += sqrt((distx * distx) + (disty * disty));
    }
    return sum;
}

double positionForCentre(vector<vector<double> > location, int N)
{
    //Initializing a pair to store coordinates of point.
    pair<double, double> curPoint(0, 0);

    //Variable to store minimum distance.
    double minDis;

    for (int i = 0; i < N; i++)
    {
        curPoint.first = curPoint.first + location[i][0];

        curPoint.second = curPoint.second + location[i][1];
    }

    //Storing centroid to curPoint.
    curPoint.first = double(curPoint.first) / (N);

    curPoint.second = double(curPoint.second) / (N);

    //Finding sum of distance of centroid with all points.
    minDis = findDis(location, curPoint);

    int k = 0;

    //Checking sum of distance from every point.
    while (k < N)
    {

        for (int i = 0; i < N, i != k; i++)
        {
            pair<double, double> newPoint;

            newPoint.first = location[i][0];

            newPoint.second = location[i][1];

            double dis = findDis(location, newPoint);

            if (dis < minDis)
            {
                curPoint = newPoint;

                minDis = dis;
            }
        }
        k++;
    }

    //Directions in which point can be shifted.
    double directions[4][2] = {{0.0, 1.0}, {0.0, -1.0}, {1.0, 0.0}, {-1.0, 0.0}};

    double shift = 100000;

    double minShift = 0.00001;

    //Loop of approximation.
    while (shift > minShift)
    {
        int flag = 0;
        for (int i = 0; i < 4; i++)
        {
            pair<double, double> newPoint;

            newPoint.first = curPoint.first + (double)shift * (directions[i][0]);

            newPoint.second = curPoint.second + (double)shift * (directions[i][1]);

            double dis = findDis(location, newPoint);

            if (dis < minDis)
            {
                curPoint = newPoint;
                minDis = dis;
                flag = 1;
                break;
            }
        }

        if (flag == 0)
            shift = shift / 2.00;
    }
    minDis = ceil(minDis*1000.0)/1000.0;
    
    return minDis;
}
