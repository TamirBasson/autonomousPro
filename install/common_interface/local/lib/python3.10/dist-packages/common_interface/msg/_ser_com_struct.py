# generated from rosidl_generator_py/resource/_idl.py.em
# with input from common_interface:msg/SerComStruct.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SerComStruct(type):
    """Metaclass of message 'SerComStruct'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('common_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'common_interface.msg.SerComStruct')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__ser_com_struct
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__ser_com_struct
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__ser_com_struct
            cls._TYPE_SUPPORT = module.type_support_msg__msg__ser_com_struct
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__ser_com_struct

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SerComStruct(metaclass=Metaclass_SerComStruct):
    """Message class 'SerComStruct'."""

    __slots__ = [
        '_pwm_l',
        '_pwm_r',
        '_dir_l',
        '_dir_r',
        '_gear',
    ]

    _fields_and_field_types = {
        'pwm_l': 'int64',
        'pwm_r': 'int64',
        'dir_l': 'boolean',
        'dir_r': 'boolean',
        'gear': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.pwm_l = kwargs.get('pwm_l', int())
        self.pwm_r = kwargs.get('pwm_r', int())
        self.dir_l = kwargs.get('dir_l', bool())
        self.dir_r = kwargs.get('dir_r', bool())
        self.gear = kwargs.get('gear', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.pwm_l != other.pwm_l:
            return False
        if self.pwm_r != other.pwm_r:
            return False
        if self.dir_l != other.dir_l:
            return False
        if self.dir_r != other.dir_r:
            return False
        if self.gear != other.gear:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def pwm_l(self):
        """Message field 'pwm_l'."""
        return self._pwm_l

    @pwm_l.setter
    def pwm_l(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pwm_l' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'pwm_l' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._pwm_l = value

    @builtins.property
    def pwm_r(self):
        """Message field 'pwm_r'."""
        return self._pwm_r

    @pwm_r.setter
    def pwm_r(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pwm_r' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'pwm_r' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._pwm_r = value

    @builtins.property
    def dir_l(self):
        """Message field 'dir_l'."""
        return self._dir_l

    @dir_l.setter
    def dir_l(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'dir_l' field must be of type 'bool'"
        self._dir_l = value

    @builtins.property
    def dir_r(self):
        """Message field 'dir_r'."""
        return self._dir_r

    @dir_r.setter
    def dir_r(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'dir_r' field must be of type 'bool'"
        self._dir_r = value

    @builtins.property
    def gear(self):
        """Message field 'gear'."""
        return self._gear

    @gear.setter
    def gear(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'gear' field must be of type 'bool'"
        self._gear = value
