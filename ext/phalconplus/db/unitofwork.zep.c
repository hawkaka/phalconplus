
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Db_UnitOfWork) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Db, UnitOfWork, phalconplus, db_unitofwork, phalconplus_db_unitofwork_method_entry, 0);

	zend_declare_property_null(phalconplus_db_unitofwork_ce, SL("modelLocator"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_db_unitofwork_ce, SL("dbServiceName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_db_unitofwork_ce, SL("objects"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_db_unitofwork_ce, SL("inserted"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_db_unitofwork_ce, SL("updated"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_db_unitofwork_ce, SL("deleted"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_db_unitofwork_ce, SL("exception"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_db_unitofwork_ce, SL("failed"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalconplus_db_unitofwork_ce->create_object = zephir_init_properties_PhalconPlus_Db_UnitOfWork;
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *dbServiceName, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dbServiceName);



	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, zephir_get_internal_ce(SS("splobjectstorage") TSRMLS_CC));
	if (zephir_has_constructor(_0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("objects"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("dbServiceName"), dbServiceName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *initial_data = NULL;
	zval *name, *model, *initial_data_param = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name, &model, &initial_data_param);

	if (!initial_data_param) {
		ZEPHIR_INIT_VAR(initial_data);
		array_init(initial_data);
	} else {
		zephir_get_arrval(initial_data, initial_data_param);
	}


	ZEPHIR_CALL_METHOD(&_0, model, "exists", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "insert", NULL, 0, name, model, initial_data);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "update", NULL, 0, name, model, initial_data);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, insert) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *initial_data = NULL, *_0;
	zval *name, *model, *initial_data_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name, &model, &initial_data_param);

	if (!initial_data_param) {
		ZEPHIR_INIT_VAR(initial_data);
		array_init(initial_data);
	} else {
		zephir_get_arrval(initial_data, initial_data_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "detach", NULL, 0, model);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 3, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_0, SS("method"), SL("insert"), 1);
	zephir_array_update_string(&_0, SL("name"), &name, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("initial_data"), &initial_data, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "attach", NULL, 0, model, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, update) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *initial_data = NULL, *_0;
	zval *name, *model, *initial_data_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name, &model, &initial_data_param);

	if (!initial_data_param) {
		ZEPHIR_INIT_VAR(initial_data);
		array_init(initial_data);
	} else {
		zephir_get_arrval(initial_data, initial_data_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "detach", NULL, 0, model);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 3, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_0, SS("method"), SL("update"), 1);
	zephir_array_update_string(&_0, SL("name"), &name, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("initial_data"), &initial_data, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "attach", NULL, 0, model, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, delete) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name, *model;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &model);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "detach", NULL, 0, model);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_0, SS("method"), SL("delete"), 1);
	zephir_array_update_string(&_0, SL("name"), &name, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "attach", NULL, 0, model, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, attach) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *info, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &info);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("objects"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "attach", NULL, 0, model, info);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, detach) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("objects"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "detach", NULL, 0, model);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, exec) {

	zval *_0, *_1, *_2, *txManager = NULL, *transaction = NULL, *e = NULL, *_3, *obj = NULL, *info = NULL, *_4, *_5$$3, *_6$$3 = NULL, *_7$$4, *_8$$4, *method$$4 = NULL, *name$$4 = NULL, *newMethod$$4 = NULL, *_9$$4 = NULL, *_10$$4 = NULL, *_12$$4, *_11$$5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	zephir_update_property_this(this_ptr, SL("exception"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("failed"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, zephir_get_internal_ce(SS("splobjectstorage") TSRMLS_CC));
	if (zephir_has_constructor(_0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("deleted"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, zephir_get_internal_ce(SS("splobjectstorage") TSRMLS_CC));
	if (zephir_has_constructor(_1 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("inserted"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, zephir_get_internal_ce(SS("splobjectstorage") TSRMLS_CC));
	if (zephir_has_constructor(_2 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("updated"), _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(txManager);
	object_init_ex(txManager, zephir_get_internal_ce(SS("phalcon\\mvc\\model\\transaction\\manager") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, txManager, "__construct", NULL, 0);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("dbServiceName"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, txManager, "setdbservice", NULL, 0, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&transaction, txManager, "get", NULL, 0);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("objects"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _4, "rewind", NULL, 0);
	zephir_check_call_status();

	/* try_start_1: */

		while (1) {
			_5$$3 = zephir_fetch_nproperty_this(this_ptr, SL("objects"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_6$$3, _5$$3, "valid", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			if (!(zephir_is_true(_6$$3))) {
				break;
			}
			_7$$4 = zephir_fetch_nproperty_this(this_ptr, SL("objects"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&obj, _7$$4, "current", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			_8$$4 = zephir_fetch_nproperty_this(this_ptr, SL("objects"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&info, _8$$4, "getinfo", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_OBS_NVAR(method$$4);
			zephir_array_fetch_string(&method$$4, info, SL("method"), PH_NOISY, "phalconplus/Db/UnitOfWork.zep", 103 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(name$$4);
			zephir_array_fetch_string(&name$$4, info, SL("name"), PH_NOISY, "phalconplus/Db/UnitOfWork.zep", 104 TSRMLS_CC);
			zephir_array_unset_string(&info, SS("method"), PH_SEPARATE);
			zephir_array_unset_string(&info, SS("name"), PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, obj, "settransaction", NULL, 0, transaction);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_INIT_NVAR(_9$$4);
			zephir_ucfirst(_9$$4, method$$4);
			ZEPHIR_INIT_NVAR(newMethod$$4);
			ZEPHIR_CONCAT_SV(newMethod$$4, "exec", _9$$4);
			ZEPHIR_CALL_METHOD_ZVAL(&_10$$4, this_ptr, newMethod$$4, NULL, 0, obj, info);
			zephir_check_call_status_or_jump(try_end_1);
			if (ZEPHIR_IS_FALSE(_10$$4)) {
				ZEPHIR_INIT_LNVAR(_11$$5);
				ZEPHIR_CONCAT_SVSV(_11$$5, "Model exec failed: ", name$$4, ":", method$$4);
				ZEPHIR_CALL_METHOD(NULL, transaction, "rollback", NULL, 0, _11$$5);
				zephir_check_call_status_or_jump(try_end_1);
			}
			_12$$4 = zephir_fetch_nproperty_this(this_ptr, SL("objects"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, _12$$4, "next", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
		}
		ZEPHIR_CALL_METHOD(NULL, transaction, "commit", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_CPY_WRT(e, EG(exception));
		if (zephir_instance_of_ev(e, zephir_get_internal_ce(SS("phalcon\\mvc\\model\\transaction\\failed") TSRMLS_CC) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			zephir_update_property_this(this_ptr, SL("failed"), obj TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("exception"), e TSRMLS_CC);
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, execInsert) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *info = NULL, *_2$$5;
	zval *model, *info_param = NULL, *initial_data = NULL, *result = NULL, *last_insert_id = NULL, *_0$$5 = NULL, *_1$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &info_param);

	zephir_get_arrval(info, info_param);


	ZEPHIR_OBS_VAR(initial_data);
	zephir_array_fetch_string(&initial_data, info, SL("initial_data"), PH_NOISY, "phalconplus/Db/UnitOfWork.zep", 130 TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(initial_data))) {
		ZEPHIR_CALL_METHOD(&result, model, "create", NULL, 0, initial_data);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&result, model, "create", NULL, 0);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_TRUE(result)) {
		ZEPHIR_CALL_METHOD(&_0$$5, model, "getwriteconnection", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&last_insert_id, _0$$5, "lastinsertid", NULL, 0);
		zephir_check_call_status();
		_1$$5 = zephir_fetch_nproperty_this(this_ptr, SL("inserted"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2$$5);
		zephir_create_array(_2$$5, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_2$$5, SL("last_insert_id"), &last_insert_id, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, _1$$5, "attach", NULL, 0, model, _2$$5);
		zephir_check_call_status();
	}
	RETURN_CCTOR(result);

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, execUpdate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *info = NULL;
	zval *model, *info_param = NULL, *result = NULL, *initial_data = NULL, *_0$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &model, &info_param);

	if (!info_param) {
		ZEPHIR_INIT_VAR(info);
		array_init(info);
	} else {
		zephir_get_arrval(info, info_param);
	}


	ZEPHIR_OBS_VAR(initial_data);
	zephir_array_fetch_string(&initial_data, info, SL("initial_data"), PH_NOISY, "phalconplus/Db/UnitOfWork.zep", 148 TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(initial_data))) {
		ZEPHIR_CALL_METHOD(&result, model, "update", NULL, 0, initial_data);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&result, model, "update", NULL, 0);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_TRUE(result)) {
		_0$$5 = zephir_fetch_nproperty_this(this_ptr, SL("updated"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _0$$5, "attach", NULL, 0, model);
		zephir_check_call_status();
	}
	RETURN_CCTOR(result);

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, execDelete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *info = NULL;
	zval *model, *info_param = NULL, *result = NULL, *_0$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &model, &info_param);

	if (!info_param) {
		ZEPHIR_INIT_VAR(info);
		array_init(info);
	} else {
		zephir_get_arrval(info, info_param);
	}


	ZEPHIR_CALL_METHOD(&result, model, "delete", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE(result)) {
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("deleted"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "attach", NULL, 0, model);
		zephir_check_call_status();
	}
	RETURN_CCTOR(result);

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, getObjects) {

	

	RETURN_MEMBER(this_ptr, "objects");

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, getInserted) {

	

	RETURN_MEMBER(this_ptr, "inserted");

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, getUpdated) {

	

	RETURN_MEMBER(this_ptr, "updated");

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, getDeleted) {

	

	RETURN_MEMBER(this_ptr, "deleted");

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, getException) {

	

	RETURN_MEMBER(this_ptr, "exception");

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, getFailed) {

	

	RETURN_MEMBER(this_ptr, "failed");

}

static zend_object_value zephir_init_properties_PhalconPlus_Db_UnitOfWork(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("modelLocator"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("modelLocator"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

