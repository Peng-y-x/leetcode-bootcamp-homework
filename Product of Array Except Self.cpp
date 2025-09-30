class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        vector<int> preProduct, sufProduct;
        preProduct.push_back(1);
        sufProduct.push_back(1);
        int hasZero = 0, zeroIndex = 0, p = 0, s = 0;
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++){
            p = preProduct.size();
            s = sufProduct.size();
            if(nums[i] == 0){
                if(nums[i] == 0){
                    hasZero++;
                    if(hasZero > 1){
                        break;
                    }
                    zeroIndex = i;
                    preProduct.push_back(preProduct[p - 1]);
                }
            }else{
                preProduct.push_back(preProduct[p - 1] * nums[i]);
            }
            if(nums[n - 1 - i] == 0){
                sufProduct.push_back(sufProduct[s - 1]);
            }else{
                sufProduct.push_back(sufProduct[s - 1] * nums[n - 1 - i]);
            }
        }
        if(hasZero > 1){
            for(int i = 0; i < nums.size(); i++){
                res.push_back(0);
            }
            return res;
        }else if(hasZero == 1){
            for(int i = 0; i < nums.size(); i++){
                res.push_back(0);
            }
            res[zeroIndex] = preProduct[zeroIndex] * sufProduct[n - 1 - zeroIndex];
            return res;
        }else{
            for(int i = 0; i < nums.size(); i++){
                res.push_back(preProduct[i] * sufProduct[n - 1- i]); 
            }
            return res;
        }
    }
};
