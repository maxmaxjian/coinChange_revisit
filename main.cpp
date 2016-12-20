#include <iostream>
#include <vector>
#include <algorithm>

class solution {
  public:
    int coinChange(const std::vector<int> & coins, int amount) {
        int result;
        if (canBeComposed(coins, amount)) {
            if (amount == 0)
                result = 0;
            else {
                std::vector<int> cands;
                for (auto it = coins.begin(); it != coins.end(); ++it) {
                    int temp = coinChange(coins, amount-*it);
                    if (temp != -1)
                        cands.push_back(1+temp);
                }
                result = *std::min_element(cands.begin(), cands.end());
            }
        }
        else {
            result = -1;
        }
        return result;
    }

  private:
    bool canBeComposed(const std::vector<int> & coins, int amount) {
        if (amount < 0)
            return false;
        else if (amount == 0)
            return true;
        else
            return std::any_of(coins.begin(), coins.end(), [&](int i){return canBeComposed(coins, amount-i);});
    }
};

int main() {
    std::vector<int> coins{1,2,5};
    int amount = 11;
    // std::vector<int> coins{2};
    // int amount = 3;

    solution soln;
    int numCoins = soln.coinChange(coins, amount);
    std::cout << "The minimum number of coins is:\n"
              << numCoins << std::endl;
}
