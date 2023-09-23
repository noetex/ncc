typedef struct
{
	uint32_t Signature; // 0x50450000
	uint16_t Machine;
	uint16_t NumSections;
	uint32_t TimeDataStamp;
	uint32_t SymbolTablePtr;    // deprecated
	uint32_t SymbolTableNumber; // deprecated
	uint16_t OptionalHeaderSize;
	uint16_t Characteristics;
} coff_header;

typedef struct
{
	uint16_t Magic;
	uint8_t  LinkerVerMajor;
	uint8_t  LinkerVerMinor;
	uint32_t CodeSize; // sum of all sections
	uint32_t InitializedDataSize;
	uint32_t UninitializedDataSize;
	uint32_t EntryPointAddress; // RVA
	uint32_t CodeBase;          // RVA
	uint32_t DataBase;          // RVA
	// what does RVA mean?
} std_coff_fields;

typedef struct
{
	uint32_t ImageBase;
	uint32_t SectionAlignment;
	uint32_t FileAlignement;
	uint16_t OSVerMajor;
	uint16_t OSVerMinor;
	uint16_t ImageVerMajor;
	uint16_t ImageVerMinor;
	uint16_t SubsystemVerMajor;
	uint16_t SubsystemVerMinor;
	uint32_t Win32VerValue; // zeros-filled
	uint32_t ImageSize;
	uint32_t HeadersSize;
	uint32_t Checksum;    // images not checked
	uint16_t Subsystem;
	uint16_t DllCharacteristics;
	uint32_t StackReserveSize;
	uint32_t StackCommitSize;
	uint32_t HeapReserveSize;
	uint32_t HeapCommitSize;
	uint32_t LoaderFlags;     // zeros-filled
	uint32_t NumRvaAndSizes;  // ??
} windows_fields;

typedef struct
{
	uint32_t ExportTable;
	uint32_t ExportTableSize;
	uint32_t ImportTable;
	uint32_t ImportTableSize;
	uint32_t ResourceTable;
	uint32_t ResourceTableSize;
	uint32_t ExceptionTable;
	uint32_t ExceptionTableSize;
	uint32_t CertificateTable;
	uint32_t CertificateTableSize;
	uint32_t BaseRelocationTable;
	uint32_t BaseRelocationTableSize;
	uint32_t Debug;   // seriously??!
	uint32_t DebugSize;
	uint32_t ArchitectureData;
	uint32_t ArchitectureDataSize;
	uint32_t GlobalPtr;
	uint32_t Zeros;
	uint32_t TlsTable;
	uint32_t TlsTableSize;
	uint32_t LoadConfigTable;
	uint32_t LoadConfigTableSize;
	uint32_t BoundImport;
	uint32_t BoundImportSize;
	uint32_t ImportAddressTable;
	uint32_t ImportAddressTableSize;
	uint32_t DelayImportDescriptor;
	uint32_t DelayImportDescriptorSize;
	uint32_t CLRRuntimeHeader;
	uint32_t CLRRuntimeHeaderSize;
	uint64_t ZerosAsWell;
} data_directories;

typedef struct
{
	uint64_t Name;
	uint32_t VirtualSize;
	uint32_t VirtualAddress;
	uint32_t RawDataSize;
	uint32_t RawDataAddress;
	uint32_t RelocationsPtr;
	uint32_t LineNumbersPtr;
	uint16_t NumRelocations;
	uint16_t NumLineNumbers;
	uint32_t Characteristics;
} section_table;

typedef struct
{
	coff_header COFFHeader;
	std_coff_fields COFFFields;
	windows_fields WindowsFields;
	data_directories DataDirectories;
	section_table SectionTable;
} portable_exe_format;
