#ifndef __BULL_FILE_SYSTEM_H__
#define __BULL_FILE_SYSTEM_H__
#ifdef __cplusplus
extern "C" {
#endif

#define FS_READ         0x01
#define FS_WRITE        0x02

typedef struct{
    int fs_type;
    union{
        void *priv;
    };
}fs_file_t;

typedef struct{
    int length;
}file_info_t;

fs_file_t* fs_open(char *name, int flags);
int fs_close(fs_file_t *fp);
int fs_write(fs_file_t *fp, char *buf, int len);
int fs_read(fs_file_t *fp, char *buf, int len);
int fs_seek(fs_file_t *fp, unsigned int offset);
int fs_delete(char *name);
int fs_is_exist(char *name);

int fs_get_info(char *name, file_info_t *info);

int fs_open2(fs_file_t* fp, const char *name, int flags, int max_size);

#ifdef __cplusplus
}
#endif

#endif //__BULL_FILE_SYSTEM_H__
