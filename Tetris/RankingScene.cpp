#include"RankingScene.h"
#include"DxLib.h"
#include"InputControl.h"
#include"SceneManager.h"

/****************************************
*�}�N����`
*****************************************/
#define RNKING_FILE          ("dat/rankingdata.csv")
#define RANKING_MAX                (10)
#define RANKING_NAME_LEN     (11)
/****************************************
*�^��`
*****************************************/
typedef struct
{
	int rank;                              //�����N
	char name[RANKING_NAME_LEN]; //���O
	int score;                             //�X�R�A
}T_RANKING;

typedef struct
{
	int x;
	int y;
}T_CURSOR;

/****************************************
*�O���[�o���ϐ��錾
*****************************************/
T_RANKING Rankig_Data[RANKING_MAX];            //�����L���O�f�[�^
T_RANKING New_Score;                               //�V�����X�R�A�f�[�^
int DispMode;                                                //�\�����[�h

T_CURSOR Cursor;                                //�J�[�\���p�ϐ�
int name_num;
/****************************************
*�v���g�^�C�v�錾
*****************************************/
void file_read(void);              //�t�@�C���ǂݍ���
void file_Write(void);                  //�t�@�C����������
void ranking_sort(void);           //�����L���O�\�[�g����
void ranking_input_name(void);     //���O���͏���
void ranking_input_name_draw(void);       //���O���͕`�揈��
/****************************************
* �V�[���Ǘ��@�\�F����������
* �� ���F�Ȃ�
* �߂�l�F�G���[���(-1:�ُ�L,-1�ȊO�F����I��)
*****************************************/
int RankingScene_Initialize(void)
{
	int ret = 0;

	file_read();

	switch (DispMode)
	{
	case RANKING_INPUT_MODE:
		Cursor.x = 0;
		Cursor.y = 0;
		name_num = 0;
		break;
	case RANKING_DISP_MODE:
	default:

		break;
	}
	return ret;
}









