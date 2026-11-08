#pragma once

class VoltageDivider {
private:
  const double R1, R2;
  double rPreCalc;
  constexpr static double maxAnalog = 1023.0;
public:
  inline static double vRef;

  VoltageDivider(double R1, double R2) : R1(R1), R2(R2) {
    rPreCalc = (R1 + R2) / R2;
  }

  double getV(int input) const {
    return input * vRef * rPreCalc / maxAnalog;
  }
};