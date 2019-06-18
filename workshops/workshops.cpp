#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

struct Workshop
{
    short start_time;
    short duration;
    short end_time;
    Workshop(short s_t, short d)
        : start_time(s_t), duration(d), end_time(s_t + d){};
};

struct Available_Workshops
{
    short n;
    vector<Workshop> workshops;
    Available_Workshops(short n) : n(n) {};
};

Available_Workshops *initialize(int start_time[], int duration[], int n)
{
    Available_Workshops *a_ws = new Available_Workshops(n);

    for (int i= 0; i < n; i++)
    {
        a_ws->workshops.push_back(Workshop(start_time[i], duration[i]));
    }

    return a_ws;
}

bool compare_starts(Workshop w1, Workshop w2)
{
    return w1.start_time < w2.start_time;
}

bool compare_ends(Workshop w1, Workshop w2)
{
    return w1.end_time < w2.end_time;
}

int CalculateMaxWorkshops(Available_Workshops *ptr)
{
    // Using greedy shit
    sort(ptr->workshops.begin(), ptr->workshops.end(), compare_starts);
    sort(ptr->workshops.begin(), ptr->workshops.end(), compare_ends);

    int available = 0;
    int lowest_start = 0;
    int lowest_end = 999999;

    auto it = ptr->workshops.begin();

    while (it != ptr->workshops.end())
    {
        lowest_end = it->end_time;
        while(it->start_time < lowest_end && it != ptr->workshops.end())
        {
            // While they intersect
            // it = ptr->workshops.erase(it);  Ok this was fucking expensive
            it++;
        }
        available++;
    }

    return available;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}

