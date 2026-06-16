# IoT Lab Integration

## Objective

Post telemetry data from a NodeMCU ESP8266 to the Zelbytes IoT Learning Lab dashboard using the HTTPS telemetry endpoint and verify successful data collection through the API Explorer.

## Device Information

* **Device ID:** gatha-irrigation-01
* **Endpoint:** https://careers.zelbytes.com/api/iot-lab/v1/telemetry
* **Node:** 54
* **Telemetry Topic:** zelbytes/lab/54/telemetry

## Architecture

The NodeMCU ESP8266 connects directly to a Wi-Fi network and sends telemetry data to the Zelbytes IoT Learning Lab using HTTPS requests. Sensor readings are packaged into JSON format and transmitted to the telemetry endpoint using the assigned API key.

## Field Mapping

| Field             | Type  | Description                  |
| ----------------- | ----- | ---------------------------- |
| temperature_c     | float | Temperature in Celsius       |
| humidity_pct      | int   | Relative humidity percentage |
| soil_moisture_pct | int   | Soil moisture percentage     |
| co2_ppm           | int   | CO₂ concentration in ppm     |

## Sample JSON Payload

```json
{
  "device_id": "gatha-irrigation-01",
  "temperature_c": 29.5,
  "humidity_pct": 90,
  "soil_moisture_pct": 31,
  "co2_ppm": 1113
}
```

## Security

* API key is stored in `secrets.h`.
* `secrets.h` is excluded from version control using `.gitignore`.
* Only `secrets.h.example` containing placeholder values is committed to GitHub.
* API keys are never included in screenshots, commits, or documentation.

## Verification

* Telemetry data was successfully transmitted to the Zelbytes IoT Learning Lab endpoint.
* More than 10 telemetry samples were recorded under device ID `gatha-irrigation-01`.
* Data was verified through **IoT Lab → API Explorer**.
* The dashboard displayed the latest values for temperature, humidity, soil moisture, and CO₂ concentration.
* The telemetry series endpoint confirmed successful storage of all submitted samples.

## Results

The IoT Lab dashboard successfully received and stored telemetry readings from the NodeMCU ESP8266. The API Explorer showed multiple recorded samples, satisfying the requirement of collecting and displaying at least 10 telemetry entries.

## Conclusion

Telemetry integration with the Zelbytes IoT Learning Lab was successfully completed using a NodeMCU ESP8266. The device authenticated using the provided API key, transmitted telemetry data over HTTPS, and the resulting data was verified through the IoT Lab API Explorer and dashboard.
