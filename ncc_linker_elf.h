#define ELF_MAGIC_ID 0x464c457f

enum elf_format
{
  ELF_FORMAT_32 = 1,
  ELF_FORMAT_64 = 2,
};

enum elf_endianness
{
  ELF_ENDIANNESS_LITTLE = 1,
  ELF_ENDIANNESS_BIG = 2,
};

enum obj_file_type
{
  OBJ_FILE_TYPE_NONE = 0,
  OBJ_FILE_TYPE_RELOCATABLE,
  OBJ_FILE_TYPE_EXECUTABLE,
  OBJ_FILE_TYPE_SHARED,
  OBJ_FILE_TYPE_CORE,

  // these are processor-specific
  OBJ_FILE_TYPE_LOPROC = 0xff00,
  OBJ_FILE_TYPE_HIPROC = 0xffff,
};

enum machine_type
{
  MACHINE_TYPE_NONE = 0,
  MACHINE_TYPE_ATNT = 1,
  MACHINE_TYPE_SPARC = 2,
  MACHINE_TYPE_INTEL_80386 = 3,
  MACHINE_TYPE_MOTOROLA_68000 = 4,
  MACHINE_TYPE_MOTOROLA_88000 = 5,
  MACHINE_TYPE_INTEL_80860 = 7,
  MACHINE_TYPE_MIPS_RS3000_BIG_ENDIAN = 8,
  MACHINE_TYPE_MIPS_RS4000_BIG_ENDIAN = 10,
  MACHINE_TYPE_RESERVED_FOR_FUTURE   /* 11-16 */
};

enum obj_file_version
{
  OBJ_FILE_VERION_NONE,
  OBJ_FILE_VERION_CURRENT,
};

typedef struct
{
  uint32_t  MagicID;
  uint8_t   Format;
  uint8_t   Endianness;
  uint8_t   CurrentVersion;
  uint8_t   TargetOS;
  uint8_t   ABIVersion;
  uint8_t   ReservedPaddingBytes[7];
  uint16_t  ObjectFileType;
  uint16_t  TargetISA;
  uint32_t  OriginalVersion;
  uintptr_t EntryPoint;
  uintptr_t ProgramHeaderTableAddress;
  uintptr_t SectionHeaderTableAddress;
  uint32_t  ArchitectureSpecificFlags;
  uint16_t  StructSize;
  uint16_t  ProgramHeaderEntrySize;
  uint16_t  ProgramHeaderEntriesCount;
  uint16_t  SectionHeaderEntrySize;
  uint16_t  SectionHeaderEntriesCount;
  uint16_t  SectionHeaderNamesEntryIndex;
} elf_header;

typedef struct
{
  uint32_t  SegmentType;
  //uint32_t  SegmentDependentFlags;  // (64-bit only)
  uintptr_t SegmentOffset;
  uintptr_t SegmentVirtualAddress;
  uintptr_t SegmentPhysicalAddress;
  uintptr_t SegmentSizeInImage;
  uintptr_t SegmentSizeInMemory;
  //uint32_t  SegmentDependentFlags;  // (32-bit only)
  uintptr_t Alignment;
} elf_program_header;

typedef struct
{
  uint32_t  NameStringOffset;
  uint32_t  Type;
  uintptr_t Attributes;
  uintptr_t SectionVirtualAddressInMemory;
  uintptr_t SectionOffsetInImage;
  uintptr_t SectionSizeInImage;
  uint32_t  LinkedSectionIndex;
  uint32_t  ExtraInfo;
  uintptr_t RequiredAlignment;
  uintptr_t EntrySize;
} elf_section_header;
