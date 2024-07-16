struct Compare {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
        if (a.first == b.first) {
            return a.second > b.second; // Lexicographically smaller string first
        }
        return a.first < b.first; // Largest integer first
    }
};

class FoodRatings {
public:
    unordered_map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, Compare>> foodsByCuisines;
    unordered_map<string, pair<int, string>> info;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; i++){
            info[foods[i]] = make_pair(ratings[i], cuisines[i]);
            foodsByCuisines[cuisines[i]].push({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        info[food].first = newRating;
        foodsByCuisines[info[food].second].push({newRating, food});
    }
    
    string highestRated(string cuisine) {
        while(!foodsByCuisines.empty() and info[foodsByCuisines[cuisine].top().second].first != foodsByCuisines[cuisine].top().first){ //the highest rating food has been changed
            foodsByCuisines[cuisine].pop(); 
        }
        return foodsByCuisines[cuisine].top().second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
