#include "Values.h"

//Ivalue
double IValue::Ampere()
{
	return ampere_;
}

string IValue::Name()
{
	return name_;
}

IValue::IValue(double val)
{
	ampere_ = val;
}

ostream& operator<< (ostream& out, IValue ival)
{
	out << ival.Ampere() << " " << ival.Name() << endl;
	return out;
}

IValue IValue::operator+ (IValue ival) const { return IValue(ampere_ + ival.Ampere()); };
IValue IValue::operator* (IValue ival) const { return IValue(ampere_ * ival.Ampere()); };
UValue IValue::operator* (RValue rval) const { return UValue(ampere_ * rval.Ohm()); };
QValue IValue::operator* (TValue tval) const { return QValue(ampere_ * tval.Seconds()); };
IValue IValue::operator- (IValue ival) const { return IValue(ampere_ - ival.Ampere()); };
IValue IValue::operator/ (IValue ival) const { return IValue(ampere_ / ival.Ampere()); };


//Uvalue
double UValue::Volt()
{
	return volt_;
}

string UValue::Name()
{
	return name_;
}

UValue::UValue(double val)
{
	volt_ = val;
}

ostream& operator<< (ostream& out, UValue uval)
{
	out << uval.Volt() << " " << uval.Name() << endl;
	return out;
}

UValue UValue::operator+ (UValue uval) const { return UValue(volt_ + uval.Volt()); };
UValue UValue::operator* (UValue uval) const { return UValue(volt_ * uval.Volt()); };
QValue UValue::operator* (CValue cval) const { return QValue(volt_ * cval.Farade()); };
UValue UValue::operator- (UValue uval) const { return UValue(volt_ - uval.Volt()); };
UValue UValue::operator/ (UValue uval) const { return UValue(volt_ / uval.Volt()); };
IValue UValue::operator/ (RValue rval) const { return IValue(volt_ / rval.Ohm()); };
RValue UValue::operator/ (IValue ival) const { return RValue(volt_ / ival.Ampere()); };


//Rvalue
double RValue::Ohm()
{
	return ohm_;
}

string RValue::Name()
{
	return name_;
}

RValue::RValue(double val)
{
	ohm_ = val;
}

ostream& operator<< (ostream& out, RValue rvalue)
{
	out << rvalue.Ohm() << " " << rvalue.Name() << endl;
	return out;
}

RValue RValue::operator+ (RValue rval) const { return RValue(ohm_ + rval.Ohm()); };
RValue RValue::operator% (RValue rval) const { return RValue((ohm_ + rval.Ohm()) / (ohm_ * rval.Ohm())); };
RValue RValue::operator* (RValue rval) const { return RValue(ohm_ * rval.Ohm()); };
UValue RValue::operator* (IValue ival) const { return UValue(ohm_ * ival.Ampere()); };
RValue RValue::operator- (RValue rval) const { return RValue(ohm_ - rval.Ohm()); };
RValue RValue::operator/ (RValue rval) const { return RValue(ohm_ / rval.Ohm()); };


//Cvalue
double CValue::Farade()
{
	return farade_;
}

string CValue::Name()
{
	return name_;
}

CValue::CValue(double val)
{
	farade_ = val;
}

ostream& operator<< (ostream& out, CValue cval)
{
	out << cval.Farade() << " " << cval.Name() << endl;
	return out;
}

CValue CValue::operator+ (CValue cval) const { return CValue(farade_ + cval.Farade()); };
CValue CValue::operator% (CValue cval) const { return CValue((farade_ + cval.Farade()) / (farade_ * cval.Farade())); };
CValue CValue::operator* (CValue cval) const { return CValue(farade_ * cval.Farade()); };
QValue CValue::operator* (UValue uval) const { return QValue(farade_ * uval.Volt()); };
CValue CValue::operator- (CValue cval) const { return CValue(farade_ - cval.Farade()); };
CValue CValue::operator/ (CValue cval) const { return CValue(farade_ / cval.Farade()); };


//Qvalue
double QValue::Coulomb()
{
	return coulomb_;
}

string QValue::Name()
{
	return name_;
}

QValue::QValue(double val)
{
	coulomb_ = val;
}

ostream& operator<< (ostream& out, QValue qval)
{
	out << qval.Coulomb() << " " << qval.Name() << endl;
	return out;
}

QValue QValue::operator+ (QValue qval) const { return QValue(coulomb_ + qval.Coulomb()); };
QValue QValue::operator* (QValue qval) const { return QValue(coulomb_ * qval.Coulomb()); };
QValue QValue::operator- (QValue qval) const { return QValue(coulomb_ - qval.Coulomb()); };
QValue QValue::operator/ (QValue qval) const { return QValue(coulomb_ / qval.Coulomb()); };
CValue QValue::operator/ (UValue uval) const { return CValue(coulomb_ / uval.Volt()); };
TValue QValue::operator/ (IValue ival) const { return TValue(coulomb_ / ival.Ampere()); };
IValue QValue::operator/ (TValue tval) const { return IValue(coulomb_ / tval.Seconds()); };
UValue QValue::operator/ (CValue cval) const { return UValue(coulomb_ / cval.Farade()); };


//Tvalue
double TValue::Seconds()
{
	return seconds_;
}

string TValue::Name()
{
	return name_;
}

TValue::TValue(double val)
{
	seconds_ = val;
}

ostream& operator<< (ostream& out, TValue tvalue)
{
	out << tvalue.Seconds() << " " << tvalue.Name() << endl;
	return out;
}

bool TValue::operator< (TValue tval) const { return seconds_ < tval.Seconds(); };
bool TValue::operator<= (TValue tval) const { return seconds_ <= tval.Seconds(); };
bool TValue::operator> (TValue tval) const { return seconds_ > tval.Seconds(); };
bool TValue::operator>= (TValue tval) const { return seconds_ >= tval.Seconds(); };
TValue TValue::operator+ (TValue tval) const { return TValue(seconds_ + tval.Seconds()); };
TValue TValue::operator* (TValue tval) const { return TValue(seconds_ * tval.Seconds()); };
QValue TValue::operator* (IValue ival) const { return QValue(seconds_ * ival.Ampere()); };
TValue TValue::operator- (TValue tval) const { return TValue(seconds_ - tval.Seconds()); };
TValue TValue::operator/ (TValue tval) const { return TValue(seconds_ / tval.Seconds()); };

