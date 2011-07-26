customer    ,a10        ;customer reference

.ifdef USING_ENCRYPTION_RECORD

group encryptedData ,a
group encryptData ,a
ccHolder    ,a40        ;credit card holder name
ccType      ,d2         ;credit card type
ccExpiry    ,d4         ;mmyy
ccNumber    ,a20        ;credit card number
endgroup
.ifdef USING_ENCRYPTION_DES3
            ,a6         ;filler to 8 char boundary for 3DES encryption
.endc
.ifdef USING_ENCRYPTION_AES
            ,a14        ;flller to 16 char boundary for AES encryption
.endc
endgroup

.else ;USING_ENCRYPTION_RECORD

group encryptedData ,a ;define groups to avoid compile errors
group encryptData ,a

ccHolder    ,a40        ;credit card holder name
ccType      ,d2         ;credit card type

.ifdef USING_ENCRYPTION_FIELD

ccExpiry    ,d4         ;mmyy

group encryptedCC ,a
ccNumber    ,a20        ;credit card number
.ifdef USING_ENCRYPTION_DES3
            ,a4         ;filler to 8 char boundary for 3DES encryption
.endc
.ifdef USING_ENCRYPTION_AES
            ,a12        ;flller to 16 char boundary for AES encryption
.endc
endgroup

.else ;USING_ENCRYPTION_FIELD

;this is the unencrypted record layout, however it can be used by the in-place encryption option in ccTest

group encryptedCC ,a    ;can only use 3DES encyption, as the size of encryptedCC is a multiple of 8, but not 16
ccExpiry    ,d4         ;mmyy
ccNumber    ,a20        ;credit card number
endgroup

.endc ;USING_ENCRYPTION_FIELD

endgroup
endgroup

.endc ;USING_ENCRYPTION_RECORD

