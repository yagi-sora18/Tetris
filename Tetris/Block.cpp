#include"Block.h"
#include"DxLib.h"
#include"InputControl.h"

/***********************************
* �}�N����`
************************************/
#define FIELD_HEIGHT           (21)         //�t�B�[���h�̃}�X�̍���
#define FIELD_WIDTH                  (12)          //�t�B�[���h�̃}�X�̕�
#define BLOCK_TROUT_SIZE       (4)                 //�u���b�N�̃}�X�T�C�Y
#define BLOCK_SIZE                   (36)          //1�u���b�N������̃T�C�Y
#define BLOCK_TYPE_MAX               (7)                   //�����Ă���u���b�N�̎��
#define BLOCK_NEXT_POS_X        (700)           //���̃u���b�N�̍��W(x���W)
#define BLOCK_NEXT_POS_Y        (500)           //���̃u���b�N�̍��W(y���W)
#define BLOCK_STOCK_POS_X       (500)           //�X�g�b�N���ꂽ�u���b�N�̍��W(x���W)
#define BLOCK_STOCK_POS_Y       (350)           //�X�g�b�N���ꂽ�u���b�N�̍��W(y���W)
#define DROP_BLOCK_INIT_X       (4)                    //�����Ă���u���b�N�̏���x���W
#define DROP_BLOCK_INIT_Y       (-1)            //�����Ă���u���b�N��y���W
#define DROP_SPEED                    (60)             //��������
#define TURN_CROCKWICE                (0)                  //���v���ɉ�]������
#define TURN_ANTICROCKWICE      (1)                    //�����v����ɉ�]������

/**************************************
*�^��`
**************************************/
enum BLOCK_STATE
{
	E_BLOCK_EMPTY,               //��u���b�N
	E_BLOCK_LIGHT_BLUE,          //���F
	E_BLOCK__YELLOW_GREEN,      //����
	E_BLOCK_YELLOW,              //���F
	E_BLOCK_ORANGE,              //�I�����W
	E_BLOCK_BLUE,                //��
	E_BLOCK_PINK,                //�s���N
	E_BLOCK_RED,                 //��
	E_BLOCK_GLAY,                //�D�F
	E_BLOCK_WALL,                //��
	E_BLOCK_IMAGE_MAX,
};

/**************************************
* �萔��`
***************************************/
const int C_BLOCK_TABLE[BLOCK_TYPE_MAX][BLOCK_TROUT_SIZE][BLOCK_TROUT_SIZE] = {
	{
		{0,0,0,0},
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{0,0,0,0},
		{2,2,2,2},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{3,0,0,0},
		{3,3,3,0},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{0,0,0,4},
		{0,4,4,4},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{0,5,5,0},
		{0,0,5,5},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{0,6,6,0},
		{6,6,0,0},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{0,7,0,0},
		{7,7,7,0},
		{0,0,0,0}
	}
};

/****************************************
* �ϐ��錾
*****************************************/





















