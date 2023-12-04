#include <iostream>
#include <cmath>
using namespace std;

float tiempo_ciclo (int dias_laborables, int numero_ordenes_anual){
  return (float)dias_laborables / numero_ordenes_anual;
}

float punto_reorden (float demanda_anual, int dias_laborables, int tiempo_espera) {
  return (demanda_anual / dias_laborables) * tiempo_espera;
}

float cantidad_economica_pedido (float costo_orden, float demanda_anual, float costo_retencion_unitario_anual) {
  return round(sqrt((2 * costo_orden * demanda_anual) / costo_retencion_unitario_anual));
}

float costo_anual_inventario (int cantidad_ordenar, float costo_retencion_unitario_anual) {
  return (cantidad_ordenar / 2) * costo_retencion_unitario_anual;
}

float costo_anual_ordenar (float demanda_anual, int cantidad_ordenar, float costo_orden) {
  return (demanda_anual / cantidad_ordenar) * costo_orden;
}

int main () {
  /* Declaración de variables */
  float costoOrden; /* Costo de una orden */
  float demandaAnual; /* Demanda anula del producto */
  float tasaInventarioU; /* Tasa de mantener una unidad de inventario (%) */
  float costoInventarioU; /* Costo de una unida de inventario */
  int diasLaborables; /* Tiempo laborable (anual) */
  int diasEspera; /* Tiempo de espera */

  system("cls");
  cout << "\n\tMODELO DE CANTIDAD ECONOMICA DE PEDIDO (EOQ)";
  cout << "\n+----------------------------------------------------------+\n";

  /* Recepción de datos */
  cout << "Ingrese el costo de una orden: "; cin >> costoOrden;
  cout << "Ingrese la demanda anual del producto: "; cin >> demandaAnual;
  cout << "Ingrese la tasa de mantener una unidad de inventario (%): "; cin >> tasaInventarioU;
  cout << "Ingrese el costo de una unidad de inventario: "; cin >> costoInventarioU;
  cout << "Ingrese el tiempo laborable (anual): "; cin >> diasLaborables;
  cout << "Ingrese el tiempo de espera: "; cin >> diasEspera;

  /* Impresión y calculo de resultados */
  int cantidadOrdenar = cantidad_economica_pedido(costoOrden, demandaAnual, (tasaInventarioU / 100) * costoInventarioU);
  int ordenesAnuales = round(demandaAnual / cantidadOrdenar);

  cout << "\n\t\tRESULTADOS OBTENIDOS";
  cout << "\n+----------------------------------------------------------+\n";
  printf("Cantidad de unidades por pedido => %d unidades", cantidadOrdenar);
  printf("\nNumero de ordenes por anio => %d", ordenesAnuales);
  printf("\nTiempo de ciclo => %.2f dias", tiempo_ciclo(diasLaborables, ordenesAnuales));
  printf("\nPunto de reorden => %.2f unidades", punto_reorden(demandaAnual, diasLaborables, diasEspera));
  printf("\nCosto anual de ordenar => %.2f", costo_anual_ordenar(demandaAnual, cantidadOrdenar, costoOrden));
  printf("\nCosto anual de mantener el inventario => %.2f", costo_anual_inventario(cantidadOrdenar, (tasaInventarioU / 100) * costoInventarioU));
  printf("\nC8osto total anual => %.2f", costo_anual_ordenar(demandaAnual, cantidadOrdenar, costoOrden) + costo_anual_inventario(cantidadOrdenar, (tasaInventarioU / 100) * costoInventarioU));

  cout << "\n\n";
}