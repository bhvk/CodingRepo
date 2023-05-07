#include <iostream>
using namespace std;

struct XRI_t
{
  uint32_t id;
};

enum class BT_t{
  None = 0,
  XRA,
  XRB,
  XRHP,
};

struct XRHP_t : public XRI_t{
  BT_t type = BT_t::XRHP;
};

int main() 
{
  XRHP_t p = {};

  cout<<"PID = "<<p.id<<endl;
}