# Debugging Log

## Day 1

### Problem

Arduino board not detected.

### Possible Causes

* Faulty USB cable
* Incorrect COM port selection
* Missing USB drivers

### Solution

1. Reconnect USB cable.
2. Check Device Manager.
3. Select correct COM port.
4. Re-upload sketch.

### Verification

Blink sketch uploaded successfully.

---

## Day 2

### Problem

LED does not turn ON.

### Checks Performed

1. LED polarity verified.
2. Resistor connected correctly.
3. Pin number checked in code.
4. GND connection verified.

### Problem

Button triggers multiple times.

### Cause

Mechanical switch bouncing.

### Solution

Implemented software debounce:

* Store last button state.
* Ignore state changes occurring within 50 ms.

### Serial Monitor Tests

Expected Output:

Button Pressed
LED ON

Button Pressed
LED OFF

### Final Result

* LED toggles correctly.
* Single press generates single event.
* No false triggering observed.

