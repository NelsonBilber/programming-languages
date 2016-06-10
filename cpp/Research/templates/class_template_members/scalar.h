#ifndef SCALAR_H
#define SCALAR_H

template<typename Scalar>
class Complex
{
    Scalar re,im;
public:
    Complex(): re{}, im{}{}

    template<typename T>
    Complex(T rr, T ii = 0): re{rr}, im{ii}{}

    Complex(const Complex&) = default; //copy constructor

    template<typename T>
    Complex(const Complex<T>& c ): re{c.real()}, im{c.img()} {}

  //  template<typename T>
  //  virtual bool mymt() = 0; //members template cannot be virtual

    Scalar real() const { return re; }
    Scalar img() const  { return im; }
};

#endif // SCALAR_H
