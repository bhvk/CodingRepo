//add(8)(2)(9) should return 19



/* //without explicit constructor [problem without explicit == https://www.geeksforgeeks.org/g-fact-93/  -->explains explicit constructor]
template <class T>
struct adder
{
    T val;

    adder(T a) : val(a) {}

    template <class T2>
    auto operator()(T2 a) -> adder<decltype(val + a)> { return val + a; }

    operator T() const { return val; }
};

template <class T>
adder<T> add(T a)
{
    return a;
}
*/


template <class T>
struct adder
{
    T val;
    explicit adder(T a) : val(a) {} //default constructor and https://www.geeksforgeeks.org/g-fact-93/  -->explains explicit
    template <class T2>
    auto operator() (T2 a)->adder<decltype(val + a)> //operator overloading https://www.geeksforgeeks.org/operator-overloading-c/
    {
        return adder<decltype(val + a)>(val + a); //https://www.geeksforgeeks.org/type-inference-in-c-auto-and-decltype/
    }

    operator T() const { return val; }
};
template <class T>
adder<T> add(T a)
{
    return adder<T>(a);
}

*****************************************************************and actual QUESTION*****************************************************************

********************************************************************************
//a_single_call_should_compare_equal_to_the_number_passed_in                   *
add(1) == 1                                                                    *
                                                                               *
//must_be_able_to_store_curried_functions                                      *
auto a = add(1)(2); a(3) == 6                                                  *
                                                                               *
//must_be_able_to_store_values                                                 *
auto a = add(1)(2); a(3); a == 3                                               *
auto b = add(3)(4); b == 7                                                     *
                                                                               *
//ust_be_usable_in_a_normal_addition                                           *
auto a = add(1)(2); a + 3 == 6                                                 *
                                                                               *                                                                               *
//must_be_usable_in_a_normal_subtraction                                       *
auto a = add(1)(2); a - 3 == 0                                                 *
                                                                               *
//should_pass_some_example_tests                                               *
add(1)(2) == 3                                                                 *
add(1)(2)(3) == 6                                                              *
add(1)(2)(3)(4) == 10                                                          *
add(1)(2)(3)(4)(5) == 15                                                       *
********************************************************************************
/*ACTUAL ACCEPTED ANSWER*/
class Yoba
{
public:
   Yoba(int n) : _n(n) {}
   Yoba operator() (int n) { return Yoba(_n + n); }
   bool operator== (int n) { return _n == n; }
   int operator+ (int n) { return _n + n; }
   int operator- (int n) { return _n - n; }
   friend bool operator== (int n, const Yoba & y) { return n == y._n; }

private:
   int _n;
};

auto add(int n)
{
   return Yoba(n);
}
