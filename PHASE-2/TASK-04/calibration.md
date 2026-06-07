# Sensor Calibration Table

## LDR Calibration

| Condition | Raw ADC Range | Classification |
|------------|--------------|---------------|
| Dark | < 200 | DARK |
| Ambient Light | 200 - 700 | AMBIENT |
| Bright Light | > 700 | BRIGHT |

### Observed Values
| Raw ADC | Voltage (V) | Classification |
|----------|------------|---------------|
| 41 | 0.200 | DARK |
| 45 | 0.220 | DARK |
| 80 | 0.430 | DARK |
| 593 | 2.898 | AMBIENT |
| 634 | 3.099 | AMBIENT |
| 781 | 3.817 | BRIGHT |
| 782 | 3.822 | BRIGHT |

---

## DHT22 Calibration

| Parameter | Measured Value |
|------------|---------------|
| Temperature | 33.9 °C |
| Humidity | 80.5 %RH |

### Notes
- Readings sampled every 2 seconds.
- Sensor allowed to stabilize before logging.

---

## HC-SR04 Calibration

| Parameter | Value |
|------------|-------|
| Measurement Unit | Centimeters |
| Estimated Accuracy | ±1 cm |
| Timeout | 30 ms |

### Sample Readings

| Distance (cm) |
|--------------|
| 18.76 |
| 20.67 |
| 33.24 |
| 56.08 |

---

## Soil Moisture Sensor Calibration

| Parameter | Value |
|------------|-------|
| DRY_ADC | 820 |
| WET_ADC | 380 |

### Sample Readings

| Raw ADC | Moisture (%) |
|----------|-------------|
| 508 | 70 |
| 518 | 68 |
| 525 | 67 |
| 530 | 65 |
| 562 | 58 |
| 577 | 55 |
| 580 | 54 |
| 596 | 50 |
| 607 | 48 |
| 631 | 42 |

### Conversion Formula

```cpp
moisturePercent = constrain(
  map(rawADC, 820, 380, 0, 100),
  0,
  100
);
```

---

## Calibration Summary

| Sensor | Calibration Result |
|----------|------------------|
| LDR | Threshold-based light classification |
| DHT22 | Stable temperature and humidity readings |
| HC-SR04 | Distance measured in centimeters |
| Soil Moisture | ADC values mapped to moisture percentage |
