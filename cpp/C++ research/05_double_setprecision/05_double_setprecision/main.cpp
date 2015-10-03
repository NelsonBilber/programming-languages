#include <iostream>
#include <iomanip>
#include <cmath>
#include <istream>
#include <sstream>

using namespace std;



void double_to_string(double number1, double number2, double number3 , double number4 , int precision = 1)
{
    ostringstream oss1;
    oss1.precision(precision);
    oss1 << fixed << number1;
    string s1 = oss1.str();
    
    ostringstream oss2;
    oss2.precision(precision);
    oss2 << fixed << number2;
    string s2 = oss2.str();
 
    ostringstream oss3;
    oss3.precision(precision);
    oss3 << fixed << number3;
    string s3 = oss3.str();
 
    ostringstream oss4;
    oss4.precision(precision);
    oss4 << fixed << number4;
    string s4 = oss4.str();
    
    std::cout <<"Result (ostring) = " << s1 <<" - " << s2 << " + " << s3  << " = " << s4 << std:: endl;
}


/*
void double_to_string(double number1, double number2, double number3 , double number4 , int precision = 1)
{
    std::stringstream ss1;
    ss1<< std::setprecision(precision) << number1;
    std::string s1 = ss1.str();
    
    std::stringstream ss2;
    ss2<< std::setprecision(precision) << number2;
    std::string s2 = ss2.str();
    
    std::stringstream ss3;
    ss3<< std::setprecision(precision) << number3;
    std::string s3 = ss3.str();
    
    std::stringstream ss4;
    ss4<< std::setprecision(precision) << number4;
    std::string s4 = ss4.str();
    
    std::cout <<"Result (sstream) = " << s1 <<" - " << s2 << " + " << s3  << " = " << s4 << std:: endl;
}
*/

void add_and_substract(double number1, double number2, double number3 , int precision = 1)
{
    int d1 = number1 * (pow(10,precision));
    int d2 = number2 * (pow(10,precision));
    int d3 = number3 * (pow(10,precision));
    
    std::cout <<"Result (precison) = " << d1 <<" - " << d2 << " + " << d3  << /*" = " << result_int <<*/ std:: endl;
    
    int n1 = static_cast<int>(d1);
    int n2 = static_cast<int>(d2);
    int n3 = static_cast<int>(d3);
    
    int result_int = 0;
    result_int = (n1 - n2) + n3;
    
    std::cout <<"Result (ints) = " << n1 <<" - " << n2 << " + " << n3  << " = " << result_int << std:: endl;
    
    d1 = static_cast<double>(n1) /*/ (pow(10,precision))*/;
    d2 = static_cast<double>(n2) /*/ (pow(10,precision))*/;
    d3 = static_cast<double>(n3) /*/ (pow(10,precision))*/;
    
    double result = static_cast<double>(result_int) / (pow(10,precision));
    
    d1 = d1 / pow(10,precision);
    d2 = d2 / pow(10,precision);
    d3 = d3 / pow(10,precision);
    
    std::cout <<"Result (precison II ) = " << d1 <<" - " << d2 << " + " << d3  << " = " << result << std:: endl;
}


void sum_and_add_operations()
{
   
    double result = 0.0;
    double operator1 = 0.0;
    double operator2 = 0.0;
    double last_result = 0.0;
    
    operator2 = 500;
    operator1 = 0.0;
    last_result = 520.58;
    
    //std::cout << std::fixed;
    
    result = operator2 - operator1 + last_result;
    //std::cout <<"Result (1) = " << operator2 <<" - " << operator1 << " + " << last_result  << " = " << result << std:: endl;
    double_to_string(operator2, operator1, last_result, result, 6);
    
    operator2 = 0.96;
    operator1 = 0.0;
    last_result = result;
    result = 0.0;
    result = operator2 - operator1 + last_result;
    //std::cout <<"Result (2) = " << operator2 <<" - " << operator1 << " + " << last_result  << " = " << result << std:: endl;
    double_to_string(operator2, operator1, last_result, result, 6);
    
    operator2 = 0.0;
    operator1 = 50000.00;
    last_result = result;
    result = 0.0;
    result = last_result - operator1;
    
    //add_and_substract(operator2, operator1, last_result, 2);
    //std::cout <<"Result (3) = " << operator2 <<" - " << operator1 << " + " << last_result  << " = " << result << std:: endl;
    double_to_string(operator2, operator1, last_result, result, 6);
    
    operator2 = 60.00;
    operator1 = 0.0;
    last_result = result;
    result = 0.0;
    result = (operator2 - operator1) + last_result;
    //std::cout <<"Result (4) = " << operator2 <<" - " << operator1 << " + " << last_result  << " = " << result << std:: endl;
    double_to_string(operator2, operator1, last_result, result, 6);
    
    operator2 = 0.0;
    operator1 = 1.00;
    last_result = result;
    result = 0.0;
    result = operator2 - operator1 + last_result;
    //std::cout <<"Result (5) = " << operator2 <<" - " << operator1 << " + " << last_result  << " = " << result << std:: endl;
    double_to_string(operator2, operator1, last_result, result, 6);
    
    operator2 = 5000000.00;
    operator1 = 0.0;
    last_result = result;
    result = 0.0;
    result = operator2 - operator1 + last_result;
    //std::cout <<"Result (6) = " << operator2 <<" - " << operator1 << " + " << last_result  << " = " << result << std:: endl;
    double_to_string(operator2, operator1, last_result, result, 6);
    
    operator2 = 0.0;
    operator1 = 0.01;
    last_result = result;
    result = 0.0;
    result = operator2 - operator1 + last_result;
    //std::cout <<"Result (7) = " << operator2 <<" - " << operator1 << " + " << last_result  << " = " << result << std:: endl;
    double_to_string(operator2, operator1, last_result, result, 6);
    
    operator2 = 0.0;
    operator1 = 0.04;
    last_result = result;
    result = 0.0;
    result = operator2 - operator1 + last_result;
    //std::cout <<"Result (8) = " << operator2 <<" - " << operator1 << " + " << last_result  << " = " << result << std:: endl;
    double_to_string(operator2, operator1, last_result, result, 6);

}


void double_pi()
{
    double f =3.14159;
    std::cout << std::setprecision(5) << f << '\n';
    std::cout << std::setprecision(9) << f << '\n';
    std::cout << std::fixed;
    std::cout << std::setprecision(5) << f << '\n';
    std::cout << std::setprecision(9) << f << '\n';
    
    double ff = f - 3.030133;
    std::cout << std::setprecision(9) << ff << " - " << "3.030133"<< '\n';
    
    double fff = ff + 3.030135;
    std::cout << std::setprecision(9) << fff << '\n';
}

int main(int argc, char *argv[])
{
    cout << "..............................................................................\n";
    sum_and_add_operations();
    cout << ".............................................................................\n";
    //double_pi();
    
    return 0;
}
