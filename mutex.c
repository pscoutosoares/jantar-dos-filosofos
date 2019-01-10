#define locked 1
#define unlocked 0

__asm void lock_mutex(void * mutex){
    
    locked    EQU 1
    unlocked  EQU 0
    
    lock_mutex PROC
        LDR     r1, =locked
    1   LDREX   r2, [r0]
        CMP     r2, r1        ; Test if mutex is locked or unlocked
    	BEQ     %f2           ; If locked - wait for it to be released, from 2
        STREXNE r2, r1, [r0]  ; Not locked, attempt to lock it
        CMPNE   r2, #1        ; Check if Store-Exclusive failed
        BEQ     %b1           ; Failed - retry from 1
        ; Lock acquired
        DMB                   ; Required before accessing protected resource
        BX      lr

    2   ; Take appropriate action while waiting for mutex to become unlocked
        WAIT_FOR_UPDATE
        B       %b1           ; Retry from 1
        ENDP
}
__asm void unlock_mutex(void * mutex){
        
    locked    EQU 1
    unlocked  EQU 0

    unlock_mutex PROC
        LDR     r1, =unlocked
        DMB                   ; Required before releasing protected resource
        STR     r1, [r0]      ; Unlock mutex
        SIGNAL_UPDATE	
        BX      lr
        ENDP
}