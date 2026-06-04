# Safety Notes

## Electrical Safety

### Rule 1

Never connect Arduino pins directly to power without understanding the circuit.

### Rule 2

Always use a current-limiting resistor with LEDs.

Recommended:

* 220 Ω to 330 Ω

### Rule 3

Disconnect USB power before modifying wiring.

### Rule 4

Check polarity before powering:

* LED Anode → Positive
* LED Cathode → Ground

### Rule 5

Avoid short circuits between:

* 5V and GND
* Output pins and GND

---

## Workspace Safety

* Keep liquids away from electronics.
* Use insulated jumper wires.
* Work on a clean table.
* Do not force connectors into headers.

---

## Software Safety

### Before Uploading Code

Verify:

* Correct Board Selected
* Correct COM Port Selected
* Sketch Compiles Successfully

### During Testing

* Monitor component temperature.
* Disconnect power if unusual heat or smell is noticed.

---

## Internship Best Practices

1. Document every wiring change.
2. Commit working code frequently using Git.
3. Test one feature at a time.
4. Keep backup copies of important sketches.
5. Record issues and fixes in debugging logs.

### Emergency Procedure

If smoke, excessive heat, or burning smell occurs:

1. Disconnect USB immediately.
2. Remove power source.
3. Inspect wiring.
4. Correct fault before reconnecting power.


