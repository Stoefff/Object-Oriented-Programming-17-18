#include <iostream>
using namespace std;

#include "FMIStudent.hpp"
#include "Master.hpp"

int main()
{
    FMIStudent st("Ivan", 43210, 1000);
    st.info();
    Human *h = &st;
    h->info();
    cout << "----------------------- \n";
    st.setName("Baj Ivan");
    st.info();
    cout << "----------------------- \n\n";

    Master master("AI", "Chesho", 21123);
    master.info();
    return 0;
}
