class Solution {
public:
    bool canBeCooked(unordered_map<string, short>& foods, unordered_map<string, vector<string>>& recipes, string& name){
        if(recipes.find(name) == recipes.end()) return false;
        foods[name] = 0; //haven't found a way to cook it yet
        for(string& food: recipes[name]){
            if(foods.find(food) != foods.end()){ //already seen such a food
                if(foods[food] == 0) return false;
            }else{
                if(canBeCooked(foods, recipes, food)){ //Not found, try to cook this food
                    foods[food] = 1;
                }else return false;
            }
        }
        foods[name] = 1;
        return true;
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unsigned long long bit = 0;
        unordered_map<string, short> foods;
        for(string& food: supplies) foods[food] = 1;
        unordered_map<string, vector<string>> cook;
        int n = recipes.size();
        for(int i = 0; i < n; i++) cook[recipes[i]] = ingredients[i];

        vector<string> res;
        for(int i = 0; i < n; i++){
            if(canBeCooked(foods, cook, recipes[i])){
                res.push_back(recipes[i]);
            }else foods[recipes[i]] = 0;
        }
        return res;
    }
};
