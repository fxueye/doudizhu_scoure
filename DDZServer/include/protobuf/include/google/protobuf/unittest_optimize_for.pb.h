// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/protobuf/unittest_optimize_for.proto

#ifndef PROTOBUF_google_2fprotobuf_2funittest_5foptimize_5ffor_2eproto__INCLUDED
#define PROTOBUF_google_2fprotobuf_2funittest_5foptimize_5ffor_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3003000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3003000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include <google/protobuf/unittest.pb.h>
// @@protoc_insertion_point(includes)
namespace protobuf_unittest {
class BarRequest;
class BarRequestDefaultTypeInternal;
extern BarRequestDefaultTypeInternal _BarRequest_default_instance_;
class BarResponse;
class BarResponseDefaultTypeInternal;
extern BarResponseDefaultTypeInternal _BarResponse_default_instance_;
class BoolMessage;
class BoolMessageDefaultTypeInternal;
extern BoolMessageDefaultTypeInternal _BoolMessage_default_instance_;
class FooClientMessage;
class FooClientMessageDefaultTypeInternal;
extern FooClientMessageDefaultTypeInternal _FooClientMessage_default_instance_;
class FooRequest;
class FooRequestDefaultTypeInternal;
extern FooRequestDefaultTypeInternal _FooRequest_default_instance_;
class FooResponse;
class FooResponseDefaultTypeInternal;
extern FooResponseDefaultTypeInternal _FooResponse_default_instance_;
class FooServerMessage;
class FooServerMessageDefaultTypeInternal;
extern FooServerMessageDefaultTypeInternal _FooServerMessage_default_instance_;
class ForeignMessage;
class ForeignMessageDefaultTypeInternal;
extern ForeignMessageDefaultTypeInternal _ForeignMessage_default_instance_;
class Int32Message;
class Int32MessageDefaultTypeInternal;
extern Int32MessageDefaultTypeInternal _Int32Message_default_instance_;
class Int64Message;
class Int64MessageDefaultTypeInternal;
extern Int64MessageDefaultTypeInternal _Int64Message_default_instance_;
class MoreBytes;
class MoreBytesDefaultTypeInternal;
extern MoreBytesDefaultTypeInternal _MoreBytes_default_instance_;
class MoreString;
class MoreStringDefaultTypeInternal;
extern MoreStringDefaultTypeInternal _MoreString_default_instance_;
class NestedTestAllTypes;
class NestedTestAllTypesDefaultTypeInternal;
extern NestedTestAllTypesDefaultTypeInternal _NestedTestAllTypes_default_instance_;
class OneBytes;
class OneBytesDefaultTypeInternal;
extern OneBytesDefaultTypeInternal _OneBytes_default_instance_;
class OneString;
class OneStringDefaultTypeInternal;
extern OneStringDefaultTypeInternal _OneString_default_instance_;
class OptionalGroup_extension;
class OptionalGroup_extensionDefaultTypeInternal;
extern OptionalGroup_extensionDefaultTypeInternal _OptionalGroup_extension_default_instance_;
class RepeatedGroup_extension;
class RepeatedGroup_extensionDefaultTypeInternal;
extern RepeatedGroup_extensionDefaultTypeInternal _RepeatedGroup_extension_default_instance_;
class SparseEnumMessage;
class SparseEnumMessageDefaultTypeInternal;
extern SparseEnumMessageDefaultTypeInternal _SparseEnumMessage_default_instance_;
class TestAllExtensions;
class TestAllExtensionsDefaultTypeInternal;
extern TestAllExtensionsDefaultTypeInternal _TestAllExtensions_default_instance_;
class TestAllTypes;
class TestAllTypesDefaultTypeInternal;
extern TestAllTypesDefaultTypeInternal _TestAllTypes_default_instance_;
class TestAllTypes_NestedMessage;
class TestAllTypes_NestedMessageDefaultTypeInternal;
extern TestAllTypes_NestedMessageDefaultTypeInternal _TestAllTypes_NestedMessage_default_instance_;
class TestAllTypes_OptionalGroup;
class TestAllTypes_OptionalGroupDefaultTypeInternal;
extern TestAllTypes_OptionalGroupDefaultTypeInternal _TestAllTypes_OptionalGroup_default_instance_;
class TestAllTypes_RepeatedGroup;
class TestAllTypes_RepeatedGroupDefaultTypeInternal;
extern TestAllTypes_RepeatedGroupDefaultTypeInternal _TestAllTypes_RepeatedGroup_default_instance_;
class TestCamelCaseFieldNames;
class TestCamelCaseFieldNamesDefaultTypeInternal;
extern TestCamelCaseFieldNamesDefaultTypeInternal _TestCamelCaseFieldNames_default_instance_;
class TestCommentInjectionMessage;
class TestCommentInjectionMessageDefaultTypeInternal;
extern TestCommentInjectionMessageDefaultTypeInternal _TestCommentInjectionMessage_default_instance_;
class TestDeprecatedFields;
class TestDeprecatedFieldsDefaultTypeInternal;
extern TestDeprecatedFieldsDefaultTypeInternal _TestDeprecatedFields_default_instance_;
class TestDeprecatedMessage;
class TestDeprecatedMessageDefaultTypeInternal;
extern TestDeprecatedMessageDefaultTypeInternal _TestDeprecatedMessage_default_instance_;
class TestDupFieldNumber;
class TestDupFieldNumberDefaultTypeInternal;
extern TestDupFieldNumberDefaultTypeInternal _TestDupFieldNumber_default_instance_;
class TestDupFieldNumber_Bar;
class TestDupFieldNumber_BarDefaultTypeInternal;
extern TestDupFieldNumber_BarDefaultTypeInternal _TestDupFieldNumber_Bar_default_instance_;
class TestDupFieldNumber_Foo;
class TestDupFieldNumber_FooDefaultTypeInternal;
extern TestDupFieldNumber_FooDefaultTypeInternal _TestDupFieldNumber_Foo_default_instance_;
class TestDynamicExtensions;
class TestDynamicExtensionsDefaultTypeInternal;
extern TestDynamicExtensionsDefaultTypeInternal _TestDynamicExtensions_default_instance_;
class TestDynamicExtensions_DynamicMessageType;
class TestDynamicExtensions_DynamicMessageTypeDefaultTypeInternal;
extern TestDynamicExtensions_DynamicMessageTypeDefaultTypeInternal _TestDynamicExtensions_DynamicMessageType_default_instance_;
class TestEagerMessage;
class TestEagerMessageDefaultTypeInternal;
extern TestEagerMessageDefaultTypeInternal _TestEagerMessage_default_instance_;
class TestEmptyMessage;
class TestEmptyMessageDefaultTypeInternal;
extern TestEmptyMessageDefaultTypeInternal _TestEmptyMessage_default_instance_;
class TestEmptyMessageWithExtensions;
class TestEmptyMessageWithExtensionsDefaultTypeInternal;
extern TestEmptyMessageWithExtensionsDefaultTypeInternal _TestEmptyMessageWithExtensions_default_instance_;
class TestExtremeDefaultValues;
class TestExtremeDefaultValuesDefaultTypeInternal;
extern TestExtremeDefaultValuesDefaultTypeInternal _TestExtremeDefaultValues_default_instance_;
class TestFieldOrderings;
class TestFieldOrderingsDefaultTypeInternal;
extern TestFieldOrderingsDefaultTypeInternal _TestFieldOrderings_default_instance_;
class TestFieldOrderings_NestedMessage;
class TestFieldOrderings_NestedMessageDefaultTypeInternal;
extern TestFieldOrderings_NestedMessageDefaultTypeInternal _TestFieldOrderings_NestedMessage_default_instance_;
class TestForeignNested;
class TestForeignNestedDefaultTypeInternal;
extern TestForeignNestedDefaultTypeInternal _TestForeignNested_default_instance_;
class TestHugeFieldNumbers;
class TestHugeFieldNumbersDefaultTypeInternal;
extern TestHugeFieldNumbersDefaultTypeInternal _TestHugeFieldNumbers_default_instance_;
class TestHugeFieldNumbers_OptionalGroup;
class TestHugeFieldNumbers_OptionalGroupDefaultTypeInternal;
extern TestHugeFieldNumbers_OptionalGroupDefaultTypeInternal _TestHugeFieldNumbers_OptionalGroup_default_instance_;
class TestHugeFieldNumbers_StringStringMapEntry;
class TestHugeFieldNumbers_StringStringMapEntryDefaultTypeInternal;
extern TestHugeFieldNumbers_StringStringMapEntryDefaultTypeInternal _TestHugeFieldNumbers_StringStringMapEntry_default_instance_;
class TestIsInitialized;
class TestIsInitializedDefaultTypeInternal;
extern TestIsInitializedDefaultTypeInternal _TestIsInitialized_default_instance_;
class TestIsInitialized_SubMessage;
class TestIsInitialized_SubMessageDefaultTypeInternal;
extern TestIsInitialized_SubMessageDefaultTypeInternal _TestIsInitialized_SubMessage_default_instance_;
class TestIsInitialized_SubMessage_SubGroup;
class TestIsInitialized_SubMessage_SubGroupDefaultTypeInternal;
extern TestIsInitialized_SubMessage_SubGroupDefaultTypeInternal _TestIsInitialized_SubMessage_SubGroup_default_instance_;
class TestJsonName;
class TestJsonNameDefaultTypeInternal;
extern TestJsonNameDefaultTypeInternal _TestJsonName_default_instance_;
class TestLazyMessage;
class TestLazyMessageDefaultTypeInternal;
extern TestLazyMessageDefaultTypeInternal _TestLazyMessage_default_instance_;
class TestMultipleExtensionRanges;
class TestMultipleExtensionRangesDefaultTypeInternal;
extern TestMultipleExtensionRangesDefaultTypeInternal _TestMultipleExtensionRanges_default_instance_;
class TestMutualRecursionA;
class TestMutualRecursionADefaultTypeInternal;
extern TestMutualRecursionADefaultTypeInternal _TestMutualRecursionA_default_instance_;
class TestMutualRecursionA_SubGroup;
class TestMutualRecursionA_SubGroupDefaultTypeInternal;
extern TestMutualRecursionA_SubGroupDefaultTypeInternal _TestMutualRecursionA_SubGroup_default_instance_;
class TestMutualRecursionA_SubMessage;
class TestMutualRecursionA_SubMessageDefaultTypeInternal;
extern TestMutualRecursionA_SubMessageDefaultTypeInternal _TestMutualRecursionA_SubMessage_default_instance_;
class TestMutualRecursionB;
class TestMutualRecursionBDefaultTypeInternal;
extern TestMutualRecursionBDefaultTypeInternal _TestMutualRecursionB_default_instance_;
class TestNestedExtension;
class TestNestedExtensionDefaultTypeInternal;
extern TestNestedExtensionDefaultTypeInternal _TestNestedExtension_default_instance_;
class TestNestedMessageHasBits;
class TestNestedMessageHasBitsDefaultTypeInternal;
extern TestNestedMessageHasBitsDefaultTypeInternal _TestNestedMessageHasBits_default_instance_;
class TestNestedMessageHasBits_NestedMessage;
class TestNestedMessageHasBits_NestedMessageDefaultTypeInternal;
extern TestNestedMessageHasBits_NestedMessageDefaultTypeInternal _TestNestedMessageHasBits_NestedMessage_default_instance_;
class TestOneof;
class TestOneofDefaultTypeInternal;
extern TestOneofDefaultTypeInternal _TestOneof_default_instance_;
class TestOneof2;
class TestOneof2DefaultTypeInternal;
extern TestOneof2DefaultTypeInternal _TestOneof2_default_instance_;
class TestOneof2_FooGroup;
class TestOneof2_FooGroupDefaultTypeInternal;
extern TestOneof2_FooGroupDefaultTypeInternal _TestOneof2_FooGroup_default_instance_;
class TestOneof2_NestedMessage;
class TestOneof2_NestedMessageDefaultTypeInternal;
extern TestOneof2_NestedMessageDefaultTypeInternal _TestOneof2_NestedMessage_default_instance_;
class TestOneofBackwardsCompatible;
class TestOneofBackwardsCompatibleDefaultTypeInternal;
extern TestOneofBackwardsCompatibleDefaultTypeInternal _TestOneofBackwardsCompatible_default_instance_;
class TestOneofBackwardsCompatible_FooGroup;
class TestOneofBackwardsCompatible_FooGroupDefaultTypeInternal;
extern TestOneofBackwardsCompatible_FooGroupDefaultTypeInternal _TestOneofBackwardsCompatible_FooGroup_default_instance_;
class TestOneof_FooGroup;
class TestOneof_FooGroupDefaultTypeInternal;
extern TestOneof_FooGroupDefaultTypeInternal _TestOneof_FooGroup_default_instance_;
class TestOptimizedForSize;
class TestOptimizedForSizeDefaultTypeInternal;
extern TestOptimizedForSizeDefaultTypeInternal _TestOptimizedForSize_default_instance_;
class TestOptionalOptimizedForSize;
class TestOptionalOptimizedForSizeDefaultTypeInternal;
extern TestOptionalOptimizedForSizeDefaultTypeInternal _TestOptionalOptimizedForSize_default_instance_;
class TestPackedExtensions;
class TestPackedExtensionsDefaultTypeInternal;
extern TestPackedExtensionsDefaultTypeInternal _TestPackedExtensions_default_instance_;
class TestPackedTypes;
class TestPackedTypesDefaultTypeInternal;
extern TestPackedTypesDefaultTypeInternal _TestPackedTypes_default_instance_;
class TestParsingMerge;
class TestParsingMergeDefaultTypeInternal;
extern TestParsingMergeDefaultTypeInternal _TestParsingMerge_default_instance_;
class TestParsingMerge_OptionalGroup;
class TestParsingMerge_OptionalGroupDefaultTypeInternal;
extern TestParsingMerge_OptionalGroupDefaultTypeInternal _TestParsingMerge_OptionalGroup_default_instance_;
class TestParsingMerge_RepeatedFieldsGenerator;
class TestParsingMerge_RepeatedFieldsGeneratorDefaultTypeInternal;
extern TestParsingMerge_RepeatedFieldsGeneratorDefaultTypeInternal _TestParsingMerge_RepeatedFieldsGenerator_default_instance_;
class TestParsingMerge_RepeatedFieldsGenerator_Group1;
class TestParsingMerge_RepeatedFieldsGenerator_Group1DefaultTypeInternal;
extern TestParsingMerge_RepeatedFieldsGenerator_Group1DefaultTypeInternal _TestParsingMerge_RepeatedFieldsGenerator_Group1_default_instance_;
class TestParsingMerge_RepeatedFieldsGenerator_Group2;
class TestParsingMerge_RepeatedFieldsGenerator_Group2DefaultTypeInternal;
extern TestParsingMerge_RepeatedFieldsGenerator_Group2DefaultTypeInternal _TestParsingMerge_RepeatedFieldsGenerator_Group2_default_instance_;
class TestParsingMerge_RepeatedGroup;
class TestParsingMerge_RepeatedGroupDefaultTypeInternal;
extern TestParsingMerge_RepeatedGroupDefaultTypeInternal _TestParsingMerge_RepeatedGroup_default_instance_;
class TestReallyLargeTagNumber;
class TestReallyLargeTagNumberDefaultTypeInternal;
extern TestReallyLargeTagNumberDefaultTypeInternal _TestReallyLargeTagNumber_default_instance_;
class TestRecursiveMessage;
class TestRecursiveMessageDefaultTypeInternal;
extern TestRecursiveMessageDefaultTypeInternal _TestRecursiveMessage_default_instance_;
class TestRepeatedScalarDifferentTagSizes;
class TestRepeatedScalarDifferentTagSizesDefaultTypeInternal;
extern TestRepeatedScalarDifferentTagSizesDefaultTypeInternal _TestRepeatedScalarDifferentTagSizes_default_instance_;
class TestRequired;
class TestRequiredDefaultTypeInternal;
extern TestRequiredDefaultTypeInternal _TestRequired_default_instance_;
class TestRequiredForeign;
class TestRequiredForeignDefaultTypeInternal;
extern TestRequiredForeignDefaultTypeInternal _TestRequiredForeign_default_instance_;
class TestRequiredOneof;
class TestRequiredOneofDefaultTypeInternal;
extern TestRequiredOneofDefaultTypeInternal _TestRequiredOneof_default_instance_;
class TestRequiredOneof_NestedMessage;
class TestRequiredOneof_NestedMessageDefaultTypeInternal;
extern TestRequiredOneof_NestedMessageDefaultTypeInternal _TestRequiredOneof_NestedMessage_default_instance_;
class TestRequiredOptimizedForSize;
class TestRequiredOptimizedForSizeDefaultTypeInternal;
extern TestRequiredOptimizedForSizeDefaultTypeInternal _TestRequiredOptimizedForSize_default_instance_;
class TestReservedFields;
class TestReservedFieldsDefaultTypeInternal;
extern TestReservedFieldsDefaultTypeInternal _TestReservedFields_default_instance_;
class TestUnpackedExtensions;
class TestUnpackedExtensionsDefaultTypeInternal;
extern TestUnpackedExtensionsDefaultTypeInternal _TestUnpackedExtensions_default_instance_;
class TestUnpackedTypes;
class TestUnpackedTypesDefaultTypeInternal;
extern TestUnpackedTypesDefaultTypeInternal _TestUnpackedTypes_default_instance_;
class Uint32Message;
class Uint32MessageDefaultTypeInternal;
extern Uint32MessageDefaultTypeInternal _Uint32Message_default_instance_;
class Uint64Message;
class Uint64MessageDefaultTypeInternal;
extern Uint64MessageDefaultTypeInternal _Uint64Message_default_instance_;
}  // namespace protobuf_unittest

namespace protobuf_unittest {

namespace protobuf_google_2fprotobuf_2funittest_5foptimize_5ffor_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_google_2fprotobuf_2funittest_5foptimize_5ffor_2eproto

// ===================================================================

class TestOptimizedForSize : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:protobuf_unittest.TestOptimizedForSize) */ {
 public:
  TestOptimizedForSize();
  virtual ~TestOptimizedForSize();

  TestOptimizedForSize(const TestOptimizedForSize& from);

  inline TestOptimizedForSize& operator=(const TestOptimizedForSize& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const TestOptimizedForSize& default_instance();

  enum FooCase {
    kIntegerField = 2,
    kStringField = 3,
    FOO_NOT_SET = 0,
  };

  static inline const TestOptimizedForSize* internal_default_instance() {
    return reinterpret_cast<const TestOptimizedForSize*>(
               &_TestOptimizedForSize_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(TestOptimizedForSize* other);

  // implements Message ----------------------------------------------

  inline TestOptimizedForSize* New() const PROTOBUF_FINAL { return New(NULL); }

  TestOptimizedForSize* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(TestOptimizedForSize* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .protobuf_unittest.ForeignMessage msg = 19;
  bool has_msg() const;
  void clear_msg();
  static const int kMsgFieldNumber = 19;
  const ::protobuf_unittest::ForeignMessage& msg() const;
  ::protobuf_unittest::ForeignMessage* mutable_msg();
  ::protobuf_unittest::ForeignMessage* release_msg();
  void set_allocated_msg(::protobuf_unittest::ForeignMessage* msg);

  // optional int32 i = 1;
  bool has_i() const;
  void clear_i();
  static const int kIFieldNumber = 1;
  ::google::protobuf::int32 i() const;
  void set_i(::google::protobuf::int32 value);

  // optional int32 integer_field = 2;
  bool has_integer_field() const;
  void clear_integer_field();
  static const int kIntegerFieldFieldNumber = 2;
  ::google::protobuf::int32 integer_field() const;
  void set_integer_field(::google::protobuf::int32 value);

  // optional string string_field = 3;
  bool has_string_field() const;
  void clear_string_field();
  static const int kStringFieldFieldNumber = 3;
  const ::std::string& string_field() const;
  void set_string_field(const ::std::string& value);
  #if LANG_CXX11
  void set_string_field(::std::string&& value);
  #endif
  void set_string_field(const char* value);
  void set_string_field(const char* value, size_t size);
  ::std::string* mutable_string_field();
  ::std::string* release_string_field();
  void set_allocated_string_field(::std::string* string_field);

  GOOGLE_PROTOBUF_EXTENSION_ACCESSORS(TestOptimizedForSize)
  FooCase foo_case() const;
  static const int kTestExtensionFieldNumber = 1234;
  static ::google::protobuf::internal::ExtensionIdentifier< ::protobuf_unittest::TestOptimizedForSize,
      ::google::protobuf::internal::PrimitiveTypeTraits< ::google::protobuf::int32 >, 5, false >
    test_extension;
  static const int kTestExtension2FieldNumber = 1235;
  static ::google::protobuf::internal::ExtensionIdentifier< ::protobuf_unittest::TestOptimizedForSize,
      ::google::protobuf::internal::MessageTypeTraits< ::protobuf_unittest::TestRequiredOptimizedForSize >, 11, false >
    test_extension2;
  // @@protoc_insertion_point(class_scope:protobuf_unittest.TestOptimizedForSize)
 private:
  void set_has_i();
  void clear_has_i();
  void set_has_msg();
  void clear_has_msg();
  void set_has_integer_field();
  void set_has_string_field();

  inline bool has_foo() const;
  void clear_foo();
  inline void clear_has_foo();

  ::google::protobuf::internal::ExtensionSet _extensions_;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::protobuf_unittest::ForeignMessage* msg_;
  ::google::protobuf::int32 i_;
  union FooUnion {
    FooUnion() {}
    ::google::protobuf::int32 integer_field_;
    ::google::protobuf::internal::ArenaStringPtr string_field_;
  } foo_;
  ::google::protobuf::uint32 _oneof_case_[1];

  friend struct protobuf_google_2fprotobuf_2funittest_5foptimize_5ffor_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class TestRequiredOptimizedForSize : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:protobuf_unittest.TestRequiredOptimizedForSize) */ {
 public:
  TestRequiredOptimizedForSize();
  virtual ~TestRequiredOptimizedForSize();

  TestRequiredOptimizedForSize(const TestRequiredOptimizedForSize& from);

  inline TestRequiredOptimizedForSize& operator=(const TestRequiredOptimizedForSize& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const TestRequiredOptimizedForSize& default_instance();

  static inline const TestRequiredOptimizedForSize* internal_default_instance() {
    return reinterpret_cast<const TestRequiredOptimizedForSize*>(
               &_TestRequiredOptimizedForSize_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(TestRequiredOptimizedForSize* other);

  // implements Message ----------------------------------------------

  inline TestRequiredOptimizedForSize* New() const PROTOBUF_FINAL { return New(NULL); }

  TestRequiredOptimizedForSize* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(TestRequiredOptimizedForSize* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int32 x = 1;
  bool has_x() const;
  void clear_x();
  static const int kXFieldNumber = 1;
  ::google::protobuf::int32 x() const;
  void set_x(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:protobuf_unittest.TestRequiredOptimizedForSize)
 private:
  void set_has_x();
  void clear_has_x();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::int32 x_;
  friend struct protobuf_google_2fprotobuf_2funittest_5foptimize_5ffor_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class TestOptionalOptimizedForSize : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:protobuf_unittest.TestOptionalOptimizedForSize) */ {
 public:
  TestOptionalOptimizedForSize();
  virtual ~TestOptionalOptimizedForSize();

  TestOptionalOptimizedForSize(const TestOptionalOptimizedForSize& from);

  inline TestOptionalOptimizedForSize& operator=(const TestOptionalOptimizedForSize& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const TestOptionalOptimizedForSize& default_instance();

  static inline const TestOptionalOptimizedForSize* internal_default_instance() {
    return reinterpret_cast<const TestOptionalOptimizedForSize*>(
               &_TestOptionalOptimizedForSize_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(TestOptionalOptimizedForSize* other);

  // implements Message ----------------------------------------------

  inline TestOptionalOptimizedForSize* New() const PROTOBUF_FINAL { return New(NULL); }

  TestOptionalOptimizedForSize* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(TestOptionalOptimizedForSize* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .protobuf_unittest.TestRequiredOptimizedForSize o = 1;
  bool has_o() const;
  void clear_o();
  static const int kOFieldNumber = 1;
  const ::protobuf_unittest::TestRequiredOptimizedForSize& o() const;
  ::protobuf_unittest::TestRequiredOptimizedForSize* mutable_o();
  ::protobuf_unittest::TestRequiredOptimizedForSize* release_o();
  void set_allocated_o(::protobuf_unittest::TestRequiredOptimizedForSize* o);

  // @@protoc_insertion_point(class_scope:protobuf_unittest.TestOptionalOptimizedForSize)
 private:
  void set_has_o();
  void clear_has_o();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::protobuf_unittest::TestRequiredOptimizedForSize* o_;
  friend struct protobuf_google_2fprotobuf_2funittest_5foptimize_5ffor_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// TestOptimizedForSize

// optional int32 i = 1;
inline bool TestOptimizedForSize::has_i() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void TestOptimizedForSize::set_has_i() {
  _has_bits_[0] |= 0x00000002u;
}
inline void TestOptimizedForSize::clear_has_i() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void TestOptimizedForSize::clear_i() {
  i_ = 0;
  clear_has_i();
}
inline ::google::protobuf::int32 TestOptimizedForSize::i() const {
  // @@protoc_insertion_point(field_get:protobuf_unittest.TestOptimizedForSize.i)
  return i_;
}
inline void TestOptimizedForSize::set_i(::google::protobuf::int32 value) {
  set_has_i();
  i_ = value;
  // @@protoc_insertion_point(field_set:protobuf_unittest.TestOptimizedForSize.i)
}

// optional .protobuf_unittest.ForeignMessage msg = 19;
inline bool TestOptimizedForSize::has_msg() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void TestOptimizedForSize::set_has_msg() {
  _has_bits_[0] |= 0x00000001u;
}
inline void TestOptimizedForSize::clear_has_msg() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void TestOptimizedForSize::clear_msg() {
  if (msg_ != NULL) msg_->::protobuf_unittest::ForeignMessage::Clear();
  clear_has_msg();
}
inline const ::protobuf_unittest::ForeignMessage& TestOptimizedForSize::msg() const {
  // @@protoc_insertion_point(field_get:protobuf_unittest.TestOptimizedForSize.msg)
  return msg_ != NULL ? *msg_
                         : *::protobuf_unittest::ForeignMessage::internal_default_instance();
}
inline ::protobuf_unittest::ForeignMessage* TestOptimizedForSize::mutable_msg() {
  set_has_msg();
  if (msg_ == NULL) {
    msg_ = new ::protobuf_unittest::ForeignMessage;
  }
  // @@protoc_insertion_point(field_mutable:protobuf_unittest.TestOptimizedForSize.msg)
  return msg_;
}
inline ::protobuf_unittest::ForeignMessage* TestOptimizedForSize::release_msg() {
  // @@protoc_insertion_point(field_release:protobuf_unittest.TestOptimizedForSize.msg)
  clear_has_msg();
  ::protobuf_unittest::ForeignMessage* temp = msg_;
  msg_ = NULL;
  return temp;
}
inline void TestOptimizedForSize::set_allocated_msg(::protobuf_unittest::ForeignMessage* msg) {
  delete msg_;
  if (msg != NULL && msg->GetArena() != NULL) {
    ::protobuf_unittest::ForeignMessage* new_msg = new ::protobuf_unittest::ForeignMessage;
    new_msg->CopyFrom(*msg);
    msg = new_msg;
  }
  msg_ = msg;
  if (msg) {
    set_has_msg();
  } else {
    clear_has_msg();
  }
  // @@protoc_insertion_point(field_set_allocated:protobuf_unittest.TestOptimizedForSize.msg)
}

// optional int32 integer_field = 2;
inline bool TestOptimizedForSize::has_integer_field() const {
  return foo_case() == kIntegerField;
}
inline void TestOptimizedForSize::set_has_integer_field() {
  _oneof_case_[0] = kIntegerField;
}
inline void TestOptimizedForSize::clear_integer_field() {
  if (has_integer_field()) {
    foo_.integer_field_ = 0;
    clear_has_foo();
  }
}
inline ::google::protobuf::int32 TestOptimizedForSize::integer_field() const {
  // @@protoc_insertion_point(field_get:protobuf_unittest.TestOptimizedForSize.integer_field)
  if (has_integer_field()) {
    return foo_.integer_field_;
  }
  return 0;
}
inline void TestOptimizedForSize::set_integer_field(::google::protobuf::int32 value) {
  if (!has_integer_field()) {
    clear_foo();
    set_has_integer_field();
  }
  foo_.integer_field_ = value;
  // @@protoc_insertion_point(field_set:protobuf_unittest.TestOptimizedForSize.integer_field)
}

// optional string string_field = 3;
inline bool TestOptimizedForSize::has_string_field() const {
  return foo_case() == kStringField;
}
inline void TestOptimizedForSize::set_has_string_field() {
  _oneof_case_[0] = kStringField;
}
inline void TestOptimizedForSize::clear_string_field() {
  if (has_string_field()) {
    foo_.string_field_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    clear_has_foo();
  }
}
inline const ::std::string& TestOptimizedForSize::string_field() const {
  // @@protoc_insertion_point(field_get:protobuf_unittest.TestOptimizedForSize.string_field)
  if (has_string_field()) {
    return foo_.string_field_.GetNoArena();
  }
  return *&::google::protobuf::internal::GetEmptyStringAlreadyInited();
}
inline void TestOptimizedForSize::set_string_field(const ::std::string& value) {
  // @@protoc_insertion_point(field_set:protobuf_unittest.TestOptimizedForSize.string_field)
  if (!has_string_field()) {
    clear_foo();
    set_has_string_field();
    foo_.string_field_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  foo_.string_field_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:protobuf_unittest.TestOptimizedForSize.string_field)
}
#if LANG_CXX11
inline void TestOptimizedForSize::set_string_field(::std::string&& value) {
  // @@protoc_insertion_point(field_set:protobuf_unittest.TestOptimizedForSize.string_field)
  if (!has_string_field()) {
    clear_foo();
    set_has_string_field();
    foo_.string_field_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  foo_.string_field_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:protobuf_unittest.TestOptimizedForSize.string_field)
}
#endif
inline void TestOptimizedForSize::set_string_field(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  if (!has_string_field()) {
    clear_foo();
    set_has_string_field();
    foo_.string_field_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  foo_.string_field_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(value));
  // @@protoc_insertion_point(field_set_char:protobuf_unittest.TestOptimizedForSize.string_field)
}
inline void TestOptimizedForSize::set_string_field(const char* value, size_t size) {
  if (!has_string_field()) {
    clear_foo();
    set_has_string_field();
    foo_.string_field_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  foo_.string_field_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:protobuf_unittest.TestOptimizedForSize.string_field)
}
inline ::std::string* TestOptimizedForSize::mutable_string_field() {
  if (!has_string_field()) {
    clear_foo();
    set_has_string_field();
    foo_.string_field_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_mutable:protobuf_unittest.TestOptimizedForSize.string_field)
  return foo_.string_field_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* TestOptimizedForSize::release_string_field() {
  // @@protoc_insertion_point(field_release:protobuf_unittest.TestOptimizedForSize.string_field)
  if (has_string_field()) {
    clear_has_foo();
    return foo_.string_field_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  } else {
    return NULL;
  }
}
inline void TestOptimizedForSize::set_allocated_string_field(::std::string* string_field) {
  if (!has_string_field()) {
    foo_.string_field_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  clear_foo();
  if (string_field != NULL) {
    set_has_string_field();
    foo_.string_field_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
        string_field);
  }
  // @@protoc_insertion_point(field_set_allocated:protobuf_unittest.TestOptimizedForSize.string_field)
}

inline bool TestOptimizedForSize::has_foo() const {
  return foo_case() != FOO_NOT_SET;
}
inline void TestOptimizedForSize::clear_has_foo() {
  _oneof_case_[0] = FOO_NOT_SET;
}
inline TestOptimizedForSize::FooCase TestOptimizedForSize::foo_case() const {
  return TestOptimizedForSize::FooCase(_oneof_case_[0]);
}
// -------------------------------------------------------------------

// TestRequiredOptimizedForSize

// required int32 x = 1;
inline bool TestRequiredOptimizedForSize::has_x() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void TestRequiredOptimizedForSize::set_has_x() {
  _has_bits_[0] |= 0x00000001u;
}
inline void TestRequiredOptimizedForSize::clear_has_x() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void TestRequiredOptimizedForSize::clear_x() {
  x_ = 0;
  clear_has_x();
}
inline ::google::protobuf::int32 TestRequiredOptimizedForSize::x() const {
  // @@protoc_insertion_point(field_get:protobuf_unittest.TestRequiredOptimizedForSize.x)
  return x_;
}
inline void TestRequiredOptimizedForSize::set_x(::google::protobuf::int32 value) {
  set_has_x();
  x_ = value;
  // @@protoc_insertion_point(field_set:protobuf_unittest.TestRequiredOptimizedForSize.x)
}

// -------------------------------------------------------------------

// TestOptionalOptimizedForSize

// optional .protobuf_unittest.TestRequiredOptimizedForSize o = 1;
inline bool TestOptionalOptimizedForSize::has_o() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void TestOptionalOptimizedForSize::set_has_o() {
  _has_bits_[0] |= 0x00000001u;
}
inline void TestOptionalOptimizedForSize::clear_has_o() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void TestOptionalOptimizedForSize::clear_o() {
  if (o_ != NULL) o_->::protobuf_unittest::TestRequiredOptimizedForSize::Clear();
  clear_has_o();
}
inline const ::protobuf_unittest::TestRequiredOptimizedForSize& TestOptionalOptimizedForSize::o() const {
  // @@protoc_insertion_point(field_get:protobuf_unittest.TestOptionalOptimizedForSize.o)
  return o_ != NULL ? *o_
                         : *::protobuf_unittest::TestRequiredOptimizedForSize::internal_default_instance();
}
inline ::protobuf_unittest::TestRequiredOptimizedForSize* TestOptionalOptimizedForSize::mutable_o() {
  set_has_o();
  if (o_ == NULL) {
    o_ = new ::protobuf_unittest::TestRequiredOptimizedForSize;
  }
  // @@protoc_insertion_point(field_mutable:protobuf_unittest.TestOptionalOptimizedForSize.o)
  return o_;
}
inline ::protobuf_unittest::TestRequiredOptimizedForSize* TestOptionalOptimizedForSize::release_o() {
  // @@protoc_insertion_point(field_release:protobuf_unittest.TestOptionalOptimizedForSize.o)
  clear_has_o();
  ::protobuf_unittest::TestRequiredOptimizedForSize* temp = o_;
  o_ = NULL;
  return temp;
}
inline void TestOptionalOptimizedForSize::set_allocated_o(::protobuf_unittest::TestRequiredOptimizedForSize* o) {
  delete o_;
  o_ = o;
  if (o) {
    set_has_o();
  } else {
    clear_has_o();
  }
  // @@protoc_insertion_point(field_set_allocated:protobuf_unittest.TestOptionalOptimizedForSize.o)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace protobuf_unittest

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_google_2fprotobuf_2funittest_5foptimize_5ffor_2eproto__INCLUDED
