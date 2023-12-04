const formulario = document.getElementById("formulario");

formulario.addEventListener('submit', function (event) {
  event.preventDefault();
  let costoOrden       = document.getElementById("costoOrden").value
  let demandaAnual     = document.getElementById("demandaAnual").value
  let tasaInventarioU  = document.getElementById("tasaInventarioU").value
  let costoInventarioU = document.getElementById("costoInventarioU").value
  let diasLaborables   = document.getElementById("diasLaborables").value
  let diasEspera       = document.getElementById("diasEspera").value

  let cantidadOrdenar = cantidad_economica_pedido(costoOrden, demandaAnual, (tasaInventarioU / 100) * costoInventarioU).toFixed(0)
  let ordenesAnuales  = (demandaAnual / cantidadOrdenar).toFixed(0)

  let result1 = document.getElementById("result1")
  let result2 = document.getElementById("result2")
  let result3 = document.getElementById("result3")
  let result4 = document.getElementById("result4")
  let result5 = document.getElementById("result5")
  let result6 = document.getElementById("result6")
  let result7 = document.getElementById("result7")

  result1.value = cantidadOrdenar
  result2.value = ordenesAnuales
  result3.value = tiempo_ciclo(diasLaborables, ordenesAnuales)
  result4.value = punto_reorden(demandaAnual, diasLaborables, diasEspera).toFixed(2)
  result5.value = costo_anual_ordenar(demandaAnual, cantidadOrdenar, costoOrden).toFixed(2)
  result6.value = costo_anual_inventario(cantidadOrdenar, (tasaInventarioU / 100) * costoInventarioU).toFixed(2)   
  result7.value = parseFloat(result5.value) + parseFloat(result6.value)

})

function tiempo_ciclo(dias_laborables, numero_ordenes_anual) {
  return (dias_laborables / numero_ordenes_anual).toFixed(2)
}

function punto_reorden(demanda_anual, dias_laborables, tiempo_espera) {
  return (demanda_anual / dias_laborables) * tiempo_espera
}

function cantidad_economica_pedido(costo_orden, demanda_anual, costo_retencion_unitario_anual) {
  return Math.sqrt((2 * costo_orden * demanda_anual) / costo_retencion_unitario_anual)
}

function costo_anual_inventario(cantidad_ordenar, costo_retencion_unitario_anual) {
  return (cantidad_ordenar / 2) * costo_retencion_unitario_anual
}

function costo_anual_ordenar(demanda_anual, cantidad_ordenar, costo_orden) {
  return (demanda_anual / cantidad_ordenar) * costo_orden
}