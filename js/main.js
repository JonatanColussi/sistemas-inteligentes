jQuery(document).ready(function($) {
	$('form').on('submit', function(event) {
		event.preventDefault();
		$('ul').html('');
		$('span').html('');

		//Pega o valor do troco
		var troco = parseInt($("#troco").val());
		
		//Quantidade de notas para o troco
		var qtdnotas = 0;
		
		//Pega o valor das notas
		var notas = $.map($("#notas").val().split(','), function(value){
			return parseInt(value);
		});
		
		//Ordena as notas em ordem crescente
		for(var i = 0; i < notas.length; i++){
			for(var j = 0; j < notas.length; j++){
				if(notas[j] > notas[i]){
					//move o maior para a variável auxiliar
					var aux = notas[j];
					//move a menor, para a posição da maior
					notas[j] = notas[i];
					//move a auxiliar para a posição da antiga menor
					notas[i] = aux;
				}
			}
		}

		//Percorre a lista na ordem contrária (Decrescente)
		for(var k = notas.length-1; k >= 0; k--){
			//Verifica quantas moedas de um determidado valor (notas[k]) podem ser utilizadas no troco
			var auxnotas = parseInt(troco/notas[k]);
			//Se foi usada ao menos uma nota de um determinado valor (notas[k]) para o troco, e insere na listagem
			if(auxnotas > 0)
				$('ul').append('<li>'+auxnotas+' x '+notas[k]+'</li>');
			//Diminui do valor do troco, o valor que já foi calculado nas notas
			troco -= auxnotas*notas[k];
			//Soma a quantidade de notas
			qtdnotas += auxnotas;
		}

		//Exibe a quantidade de notas que deve ser utilizada para o troco 
		$('span').text('Serão utilizadas '+qtdnotas+' notas(s) para o troco');
	});
});