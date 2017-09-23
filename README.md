# Librería Arduino Double EMA
Librería para Arduino que implementa un filtro exponencial (EMA) con doble frecuencia de corte. La librería permite realizar filtros de paso banda y stop banda.

Más información https://www.luisllamas.es/libreria-arduino-double-ema/

## Instrucciones de uso

### Constructor

El filtro Double EMA se instancia a través de su constructor que recibe los parámetros AlphaLow y AlphaHigh, correspondientes a la frecuencia de corte inferior y superior. El orden de los parámetros en el constructor es indiferente, la función asignará correctamente los valores de Alpha en función de su valor.

```c++
DoubleEMAFilter<int> doubleEMAFilter(const size_t alpha1, const size_t alpha2);
```

### Filtrar señal
```c++
// Añadir un nuevo valor al filtro y devolver el valor filtrado Band Pass
doubleEMAFilter.AddValue(value);
 
//Obtiene el ultimo valor filtrado Band Pass (el mismo que el devuelto al añadir el valor al filtro)
doubleEMAFilter.GetBandPass();
 
//Obtiene el ultimo valor filtrado Band Stop
doubleEMAFilter.GetBandStop();
```

## Ejemplos
La librería Double EMA Filter incluye los siguientes ejemplos para ilustrar su uso.
* DoubleEMAFilterInt: Ejemplo de filtrado para variables integer.
* DoubleEMAFilterFloat: Ejemplo de filtrado para variables float.
