	PRESERVE8
	THUMB   
		

; ====================== zone de réservation de données,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly
	

;Section RAM (read write):
	area    maram,data,readwrite
	;export GestionSon_Index
	import Son
	import LongueurSon
	import PWM_Set_Value_TIM3_Ch3
		
	export SortieSon
GestionSon_Index dcd 8000
Longueure_max dcd 719
SortieSon dcd 360
	
; ===============================================================================================
	


		
;Section ROM code (read only) :		
	area    moncode,code,readonly
; écrire le code ici		
	export GestionSon_callback
	export GestionSon_Start
		
GestionSon_callback proc
	; récupération de l'index courant
		ldr r1, =GestionSon_Index
		ldr r0, [r1]
	
	; récupération de la taille du tableau
		ldr r2, =LongueurSon
		ldr r3, [r2]
		
	; coparaison de i et taille du tableau
		cmp r0, r3
		
	; Si plus petit = dans tableau 
		ble echelonner
	; sinon on met à la moitié de l'intervalle [0,719]
		mov r3, #360
		b return 

echelonner 
	; sauvegarder l'index 
		ldr r0, [r1]
	
	; remettre a l'echelle 0 à 719
		ldr r2, =Son
		ldrsh r3, [r2, r0, lsl #1]
		;sxth r3, r3
		; (valeur son + 32768)*720 / 65536 
		add r3, #32768
		mov r2, #720
		mul r3, r2
		asr r3, r3, #16
		
	; Post incrementation 
		add r0, #1
		str r0, [r1]
		
return 
		ldr r2, =SortieSon
		str r3, [r2]
		
		; stocker lr
		push {lr}
		
		; aller a la fonction
		mov r0, r3
		bl PWM_Set_Value_TIM3_Ch3

		pop {lr}
		bx lr
		
	endp
		
GestionSon_Start proc
		mov r0, #0
		ldr r1, =GestionSon_Index
		str r0, [r1]
		bx lr
	
	endp


		
		
	END	