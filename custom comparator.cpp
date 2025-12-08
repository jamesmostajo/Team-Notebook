struct sort_y{
    bool operator()(
        const pair<int, int> p1, const pair<int, int> p2)
        const {
            return p1.second < p2.second; // prioiritize maximum
            return p1.second > p2.second; // prioritize minimum
        } 
}

priority_queue<pair<int, int>, vector<pair<int, int>, sort_y> pq;