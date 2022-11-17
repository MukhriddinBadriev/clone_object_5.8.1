#include <iostream>
#include <vector>
#include <memory>

class tridiagonal_matrix
{
public:
    std::vector<double> m_down;
    std::vector<double> m_upper;
    std::vector<double> m_middle;
    tridiagonal_matrix(
        const std::vector<double>& down,
        const std::vector<double>& upper,
        const std::vector<double>& middle) :
        m_down{ down }, m_upper{ upper }, m_middle{ middle }
    {};
    ~tridiagonal_matrix() { std::cout << "destructor called\n"; }

    std::unique_ptr<tridiagonal_matrix> clone() {
        
        auto ptr1 = std::make_unique<tridiagonal_matrix>(m_down, m_upper, m_middle);
        return ptr1;
    }
};

int main()
{
    auto down = std::vector<double>{ -4.0, 5.0 };
    auto upper = std::vector<double>{ 14.0, 8.0 };
    auto middle = std::vector<double>{ 3.0, 1.0, 7.0 };
    auto matrix = std::make_unique<tridiagonal_matrix>(
        down,
        upper,
        middle
        );

    auto matrix_clone = matrix->clone();

    auto i_d = matrix_clone->m_down.begin();
    while (i_d != matrix_clone->m_down.end()) {
        std::cout << *i_d << std::endl;
        i_d++;
    }

    auto i_u = matrix_clone->m_upper.begin();
    while (i_u != matrix_clone->m_upper.end()) {
        std::cout << *i_u << std::endl;
        i_u++;
    }

    auto i_m = matrix_clone->m_middle.begin();
    while (i_m != matrix_clone->m_middle.end()) {
        std::cout << *i_m << std::endl;
        i_m++;
    }

    return 0;
}