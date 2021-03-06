#include "model_inisetting.h"

Model_iniSetting::Model_iniSetting()
{

}

/*************************************************************
/函数功能：写INI文件
/函数参数：file:写入文件路径   Section：写入的节点  Key：写入的键值   value：写入的值
/函数返回：无
*************************************************************/
void Model_iniSetting::WriteIni(QString file,QString Section,QString Key,QVariant value)
{
    QSettings *pIni;
    pIni = new QSettings(file, QSettings::IniFormat);
    pIni->setValue("/"+Section+"/"+Key, value);//写入数据
    delete pIni;
}

/*************************************************************
/函数功能：读INI文件
/函数参数：file:读文件路径   Section：读出的节点  Key：读出的键值   value：读出的值
/函数返回：无
*************************************************************/
void Model_iniSetting::ReadIni(QString file,QString Section,QString Key,QVariant *value)
{
    QSettings *pIni ;
    pIni = new QSettings(file, QSettings::IniFormat);
    *value = pIni->value("/"+Section+"/"+Key);
    //qDebug()<<__FUNCTION__<<Key<<value;

    //QString sArg = "";
    //sArg = pIni->value("/setting/arg1").toString();
    //qDebug("arg1 = %s\n", sArg.toStdString().data());
    delete pIni;
}


/*************************************************************
/函数功能：读取邮箱
/函数参数：路径   键值
/函数返回：值
*************************************************************/
QVariant Model_iniSetting::ReadIni_email()
{
    QVariant value;
    ReadIni(REPORTPath("conf/config.ini"),"mailto_list","mailto_list",&value);
    return value;
}

/*************************************************************
/函数功能：写邮箱
/函数参数：路径 Key：写入的键值   value：写入的值
/函数返回：无
*************************************************************/
void Model_iniSetting::WriteIni_email(QVariant value)
{
    WriteIni(REPORTPath("conf/config.ini"),"mailto_list","mailto_list",value);
}




/*************************************************************
/函数功能：读取项目信息
/函数参数：
/函数返回：信息
*************************************************************/
QVariant Model_iniSetting::ReadIni_item(QString infoType)
{
    QVariant value;
    ReadIni(configPath("config.ini"),"ITEM_Information",infoType,&value);
    return value;
}

/*************************************************************
/函数功能：写项目信息
/函数参数：信息类型   value：写入的值
/函数返回：无
*************************************************************/
void Model_iniSetting::WriteIni_item(QString infoType ,QVariant value)
{
    WriteIni(configPath("config.ini"),"ITEM_Information",infoType,value);
}


/*************************************************************
/函数功能：读取项目信息
/函数参数：
/函数返回：信息
*************************************************************/
QVariant Model_iniSetting::ReadIni_user(QString infoType)
{
    QVariant value;
    ReadIni(configPath("config.ini"),"USER_Information",infoType,&value);
    return value;
}

/*************************************************************
/函数功能：写项目信息
/函数参数：信息类型   value：写入的值
/函数返回：无
*************************************************************/
void Model_iniSetting::WriteIni_user(QString infoType ,QVariant value)
{
    WriteIni(configPath("config.ini"),"USER_Information",infoType,value);
}

#if 0

/*************************************************************
/函数功能：读取项目名
/函数参数：
/函数返回：项目名
*************************************************************/
QString Model_iniSetting::ReadIni_item()
{
    QVariant value;
    ReadIni(configPath("config.ini"),"ITEM_Information","item_Name",&value);
    return value.toString();
}

/*************************************************************
/函数功能：写项目名
/函数参数：value：写入的值
/函数返回：无
*************************************************************/
void Model_iniSetting::WriteIni_item(QVariant value)
{
    WriteIni(configPath("config.ini"),"ITEM_Information","item_Name",value);
}


/*************************************************************
/函数功能：读取工作电流
/函数参数：
/函数返回：值
*************************************************************/
int Model_iniSetting::ReadIni_WorkCurrent()
{
    QVariant value;
    ReadIni(configPath("config.ini"),"ITEM_Information","WorkCurrent",&value);
    return value.toInt();
}

/*************************************************************
/函数功能：写工作电流
/函数参数：value：写入的值
/函数返回：无
*************************************************************/
void Model_iniSetting::WriteIni_WorkCurrent(QVariant value)
{
    WriteIni(configPath("config.ini"),"ITEM_Information","WorkCurrent",value);
}



/*************************************************************
/函数功能：读取循环次数
/函数参数：
/函数返回：值
*************************************************************/
int Model_iniSetting::ReadIni_WorkFrequency()
{
    QVariant value;
    ReadIni(configPath("config.ini"),"ITEM_Information","WorkFrequency",&value);
    return value.toInt();
}

/*************************************************************
/函数功能：写循环次数
/函数参数：value：写入的值
/函数返回：无
*************************************************************/
void Model_iniSetting::WriteIni_WorkFrequency(QVariant value)
{
    WriteIni(configPath("config.ini"),"ITEM_Information","WorkFrequency",value);
}


/*************************************************************
/函数功能：读取创建报告
/函数参数：
/函数返回：值
*************************************************************/
bool Model_iniSetting::ReadIni_ReportCreat()
{
    QVariant value;
    ReadIni(configPath("config.ini"),"ITEM_Information","ReportCreat",&value);
    return value.toBool();
}

/*************************************************************
/函数功能：写创建报告
/函数参数：value：写入的值
/函数返回：无
*************************************************************/
void Model_iniSetting::WriteIni_ReportCreat(QVariant value)
{
    WriteIni(configPath("config.ini"),"ITEM_Information","ReportCreat",value);
}

/*************************************************************
/函数功能：读取定义信息
/函数参数：
/函数返回：值
*************************************************************/
QString Model_iniSetting::ReadIni_defineInfo(QString str)
{
    QVariant value;
    ReadIni(configPath("config.ini"),"TEST_DEFINE_INFO",str,&value);
    return value.toString();
}

/*************************************************************
/函数功能：写定义信息
/函数参数：value：写入的值
/函数返回：无
*************************************************************/
void Model_iniSetting::WriteIni_defineInfo(QString str,QVariant value)
{
    WriteIni(configPath("config.ini"),"TEST_DEFINE_INFO",str,value);
}
#endif
