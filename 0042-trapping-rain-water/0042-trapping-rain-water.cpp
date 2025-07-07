class Solution {
public:
    int trap(vector<int>& height) 
    {
    int n = height.size();  // ye ma height array ka size store karo

    // Pehle do arrays bnao, prev aur next jisme har index ke liye 
    // uske left aur right ka maximum height store hoga
    int prev[n];  // left side ke sabse bada element har index ke liye
    int next[n];  // right side ke sabse bada element har index ke liye
    int water = 0;  // total pani store kare ka rakh ke chalo
    int max = height[0];  // shuruwat ma left ka max height, pehla element maan ke chalo
    prev[0] = -1;  // pehla element ka koi left nahi hai, isliye -1 daal diya

    // Pehla loop left side ka maximum har index ke liye nikaal raha hai
    for (int i = 1; i < n; i++) {
        prev[i] = max;  // ab tak ka max element daal do prev[i] ma
        if (max < height[i]) {  // agar naya element bada hai, to max update karo
            max = height[i];
        }
    }

    // Debugging ke liye prev array print kar sakat ho
    for (int i = 0; i < n; i++) {
        cout << prev[i] << " ";
    }
    cout << endl;

    next[n - 1] = -1;  // last element ka koi right nahi hai, isliye -1
    max = height[n - 1];  // ab max right side se start ho ke last element hoga

    // Dusra loop right side ka maximum har index ke liye nikaal raha hai
    for (int i = n - 2; i >= 0; i--) {
        next[i] = max;  // right side ka ab tak ka max daal do next[i] ma
        if (max < height[i]) {  // agar naya element bada hai, to max update karo
            max = height[i];
        }
    }

    // naya array banane ki jagah, prev array ke andar dono ka minimum daal sakte ho
    // jisme har index pe prev aur next ka minimum height nikaal lo
    int mini[n];
    for (int i = 0; i < n; i++) {
        mini[i] = min(prev[i], next[i]);  // prev aur next ke minimum ko store karo mini ma
    }

    // Ab pani ka calculation hoga har index pe using height aur mini array
    for (int i = 1; i < n - 1; i++) {  // 0 aur n wale index humko nahi chahiye
        if (height[i] <= mini[i]) {  // agar current height kam hai mini se
            water += mini[i] - height[i];  // pani ka contribution add karo
        }
    }

    return water;  // total pani ka amount return karo

    }
};