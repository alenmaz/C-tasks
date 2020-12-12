#include <iostream>

using namespace std;

class IValue;
class RValue;
class UValue;
class CValue;
class TValue;
class QValue;

class IValue
{
private:
	double ampere_ = 0.0;
	string name_ = "A";
public:
	IValue() {};
	double Ampere();
	string Name();
	IValue(double val);
	friend ostream& operator<< (ostream& out, IValue ivalue);
	IValue operator+ (IValue ival) const;
	IValue operator* (IValue ival) const;
	UValue operator* (RValue rval) const;
	QValue operator* (TValue tval) const;
	IValue operator- (IValue ival) const;
	IValue operator/ (IValue ival) const;
};

class UValue
{
private:
	double volt_ = 0.0;
	string name_ = "V";
public:
	UValue() {};
	double Volt();
	string Name();
	UValue(double val);
	friend ostream& operator<< (ostream& out, UValue uvalue);
	UValue operator+ (UValue uval) const;
	UValue operator* (UValue uval) const;
	QValue operator* (CValue cval) const;
	UValue operator- (UValue uval) const;
	UValue operator/ (UValue uval) const;
	IValue operator/ (RValue rval) const;
	RValue operator/ (IValue ival) const;
};

class RValue
{
private:
	double ohm_ = 0.0;
	string name_ = "Ohm";
public:
	RValue() {};
	double Ohm();
	string Name();
	RValue(double val);
	friend ostream& operator<< (ostream& out, RValue rvalue);
	RValue operator+ (RValue rval) const;
	RValue operator% (RValue rval) const;
	RValue operator* (RValue rval) const;
	UValue operator* (IValue ival) const;
	RValue operator- (RValue rval) const;
	RValue operator/ (RValue rval) const;
};

class CValue
{
private:
	double farade_ = 0.0;
	string name_ = "F";
public:
	CValue() {};
	double Farade();
	string Name();
	CValue(double val);
	friend ostream& operator<< (ostream& out, CValue cvalue);
	CValue operator+ (CValue cval) const;
	CValue operator% (CValue cval) const;
	CValue operator* (CValue cval) const;
	QValue operator* (UValue uval) const;
	CValue operator- (CValue cval) const;
	CValue operator/ (CValue cval) const;
};

class QValue
{
private:
	double coulomb_ = 0.0;
	string name_ = "C";
public:
	QValue() {};
	double Coulomb();
	string Name();
	QValue(double val);
	friend ostream& operator<< (ostream& out, QValue qvalue);
	QValue operator+ (QValue qval) const;
	QValue operator* (QValue qval) const;
	QValue operator- (QValue qval) const;
	QValue operator/ (QValue qval) const;
	CValue operator/ (UValue qval) const;
	TValue operator/ (IValue ival) const;
	IValue operator/ (TValue tval) const;
	UValue operator/ (CValue cval) const;
};

class TValue
{
private:
	double seconds_ = 0.0;
	string name_ = "s";
public:
	TValue() {};
	double Seconds();
	string Name();
	TValue(double val);
	friend ostream& operator<< (ostream& out, TValue tvalue);
	bool operator< (TValue tval) const;
	bool operator<= (TValue tval) const;
	bool operator> (TValue tval) const;
	bool operator>= (TValue tval) const;
	TValue operator+ (TValue tval) const;
	TValue operator* (TValue tval) const;
	QValue operator* (IValue ival) const;
	TValue operator- (TValue tval) const;
	TValue operator/ (TValue tval) const;
};