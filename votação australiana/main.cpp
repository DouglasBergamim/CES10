#include <iostream>
#include <limits>
#include <string>
#include<array>


constexpr auto max_size =
        std::numeric_limits<std::streamsize>::max();

int main () {
    std::array<std::string, 20> candidates;
    int n;

    std::cin >> n;
    std::cin.ignore(max_size, '\n');

    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, candidates[i]);
    }

    std::array<std::array<int, 20>, 1000> ballot{};
    std::array<bool, 20> loser{};
    std::array<int, 20> ranking{};
    int linha = 0;
    int round = 0;

    for (; linha < 1000; ++linha) {
        for (int j = 0; j < n; ++j) {
            std::cin >> ballot[linha][j];
        }
    }

    for (; round < n; ++round) {
        for (int i = 0; i < linha; ++i) {
            int j = 0;
            for (int m = 0; m < 20; ++m) {
                if (ballot[i][j] == m + 1 && loser[m] == false) {
                    ++ranking[m];
                    break;
                }

                if(ballot[i][j] == m + 1 && loser[m] == true) {
                    ++j;
                    m=-1;
                }
            }
        }

        int max_value;
        int min_value;

        for(int i = 0; i < 20; ++i){
            if(ranking[i]!=0){
                max_value = min_value = ranking[i];
                break;
            }
        }

        for (int m = 0; m < 20; ++m) {
            if (loser[m] == false && max_value <= ranking[m]) {
                max_value = ranking[m];
            }

            if (loser[m] == false && min_value >= ranking[m]) {
                min_value = ranking[m];
            }
        }

        for (int m = 0; m < 20; ++m){
            if (loser[m] == false && ranking[m] == min_value && min_value != max_value) {
                loser[m] = true;
            }

            if (loser[m] == false && ranking[m] >= linha/2) {
                std::cout << candidates[m] << '\n';
                round = n;
                return 0;
            }
        }

        for (int t =0; t < 20; ++t){
            ranking[t]=0;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (loser[i] == false) {
            std::cout << candidates[i] <<'\n';
        }
    }
}

