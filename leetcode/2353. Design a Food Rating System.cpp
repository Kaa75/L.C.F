#include <bits/stdc++.h>

using namespace std;

class FoodRatings {
public:
    map<string, int> foodRatings;  // Stores food -> rating
    map<string, string> foodToCuisine;  // Stores food -> cuisine
    map<string, set<pair<int, string>>> cuisineFoods;  // Cuisine -> sorted foods (by -rating, name)

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodRatings[foods[i]] = ratings[i];
            foodToCuisine[foods[i]] = cuisines[i];
            cuisineFoods[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        auto& foodsSet = cuisineFoods[cuisine];

        // Find and remove the old rating
        foodsSet.erase({-foodRatings[food], food});
        
        // Update rating
        foodRatings[food] = newRating;
        
        // Insert the new rating
        foodsSet.insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        return (*cuisineFoods[cuisine].begin()).second;
    }
};
    /**
     * Your FoodRatings object will be instantiated and called as such:
     * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
     * obj->changeRating(food,newRating);
     * string param_2 = obj->highestRated(cuisine);
     */